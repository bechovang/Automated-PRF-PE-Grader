import os
import subprocess

# --- CONFIGURATION ---
SUBMISSIONS_ROOT_DIR = "submissions"  # Thư mục chứa bài nộp của sinh viên
EXAM_ROOT_DIR = "exam"                # Thư mục chứa các đề thi
QUESTIONS = ["Q1", "Q2", "Q3", "Q4"]
TIMEOUT_SECONDS = 5                   # Thời gian tối đa để một chương trình chạy

# --- SIMPLE TEXT OUTPUT (NO COLORS) ---
class bcolors:
    HEADER = ''
    OKBLUE = ''
    OKCYAN = ''
    OKGREEN = ''
    WARNING = ''
    FAIL = ''
    ENDC = ''
    BOLD = ''
    UNDERLINE = ''

def parse_test_cases(file_path):
    """Phân tích file TESTCASE.txt và trả về một dictionary chứa các test case."""
    if not os.path.exists(file_path):
        print(f"{bcolors.FAIL}Lỗi: Không tìm thấy file test case '{file_path}'.{bcolors.ENDC}")
        return None

    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()

    test_cases = {}
    question_blocks = content.split('[')[1:]

    for block in question_blocks:
        parts = block.split(']', 1)
        question_name = parts[0].strip()
        test_cases[question_name] = []
        
        block_content = parts[1].strip()
        cases = block_content.split('---')

        for case in cases:
            if not case.strip():
                continue
            
            io_parts = case.strip().split('EXPECTED_OUTPUT:', 1)
            if len(io_parts) == 2:
                input_part = io_parts[0].replace('INPUT:', '', 1).strip()
                output_part = io_parts[1].strip()
                
                test_cases[question_name].append({
                    'input': input_part,
                    'expected_output': output_part
                })
            
    return test_cases

def normalize_output(text):
    """Chuẩn hóa output: chỉ lấy nội dung sau 'OUTPUT:' và loại bỏ khoảng trắng thừa."""
    if "OUTPUT:" in text:
        relevant_text = text.split("OUTPUT:", 1)[1]
    else:
        relevant_text = text
    
    return "\n".join(line.strip() for line in relevant_text.strip().splitlines() if line.strip())

def grade_student(student_id, all_test_cases):
    """Chấm tất cả các câu hỏi cho một sinh viên và trả về một dictionary điểm số."""
    print(f"\n{bcolors.HEADER}{'='*20} Đang chấm bài sinh viên: {student_id} {'='*20}{bcolors.ENDC}")
    student_dir = os.path.join(SUBMISSIONS_ROOT_DIR, student_id)
    student_scores = {}

    for q_name in QUESTIONS:
        print(f"\n{bcolors.BOLD}--- Câu hỏi {q_name} ---{bcolors.ENDC}")
        
        exe_path = os.path.join(student_dir, q_name, "run", f"{q_name}.exe")
        
        if not os.path.exists(exe_path):
            print(f"{bcolors.FAIL}LỖI: Không tìm thấy file '{q_name}.exe'. Bỏ qua.{bcolors.ENDC}")
            student_scores[q_name] = -1.0
            continue

        if q_name not in all_test_cases:
            print(f"{bcolors.WARNING}CẢNH BÁO: Không tìm thấy test case cho {q_name}. Bỏ qua.{bcolors.ENDC}")
            student_scores[q_name] = -1.0
            continue

        question_test_cases = all_test_cases[q_name]
        passed_count = 0
        total_cases = len(question_test_cases)

        for i, case in enumerate(question_test_cases):
            test_num = i + 1
            test_input = case['input']
            expected_output = normalize_output(case['expected_output'])

            try:
                process = subprocess.run(
                    [exe_path], input=test_input, capture_output=True,
                    text=True, encoding='utf-8', timeout=TIMEOUT_SECONDS
                )
                
                if process.returncode != 0:
                    # CẬP NHẬT Ở ĐÂY
                    print(f"  {q_name} - Test Case #{test_num}: {bcolors.FAIL}LỖI CHẠY CHƯƠNG TRÌNH (RUNTIME ERROR){bcolors.ENDC}")
                    if process.stderr:
                        print(f"    Thông điệp lỗi: {process.stderr.strip()}")
                    continue

                actual_output = normalize_output(process.stdout)

                if actual_output == expected_output:
                    # CẬP NHẬT Ở ĐÂY
                    print(f"  {q_name} - Test Case #{test_num}: {bcolors.OKGREEN}ĐÚNG (PASS){bcolors.ENDC}")
                    passed_count += 1
                else:
                    # CẬP NHẬT Ở ĐÂY
                    print(f"  {q_name} - Test Case #{test_num}: {bcolors.FAIL}SAI (FAIL){bcolors.ENDC}")
                    print(f"    {bcolors.OKBLUE}--> Input đã sử dụng:{bcolors.ENDC}")
                    print(f"      '''\n      {test_input}\n      '''")
                    print(f"    {bcolors.WARNING}--> Kết quả mong muốn:{bcolors.ENDC}")
                    print(f"      '''\n      {expected_output}\n      '''")
                    print(f"    {bcolors.FAIL}--> Kết quả của sinh viên:{bcolors.ENDC}")
                    print(f"      '''\n      {actual_output}\n      '''")

            except subprocess.TimeoutExpired:
                # CẬP NHẬT Ở ĐÂY
                print(f"  {q_name} - Test Case #{test_num}: {bcolors.FAIL}LỖI THỜI GIAN (TIMEOUT){bcolors.ENDC}")
            except Exception as e:
                # CẬP NHẬT Ở ĐÂY
                print(f"  {q_name} - Test Case #{test_num}: {bcolors.FAIL}LỖI SCRIPT CHẤM BÀI: {e}{bcolors.ENDC}")

        score = (passed_count / total_cases) * 100 if total_cases > 0 else 0
        student_scores[q_name] = score

    return student_scores

def display_summary(student_id, scores):
    """In bảng tổng kết điểm cuối cùng cho một sinh viên."""
    print(f"\n{bcolors.OKBLUE}{'='*15} Bảng điểm của sinh viên {student_id} {'='*15}{bcolors.ENDC}")
    total_score = 0
    num_graded_questions = 0

    for q_name, score in scores.items():
        if score < 0:
            print(f"  {q_name:<5}: {bcolors.WARNING}KHÔNG CHẤM (Không tìm thấy file){bcolors.ENDC}")
        else:
            color = bcolors.OKGREEN if score == 100 else (bcolors.WARNING if score > 0 else bcolors.FAIL)
            print(f"  {q_name:<5}: {color}{score:6.2f}%{bcolors.ENDC}")
            total_score += score
            num_graded_questions += 1
    
    average_score = total_score / num_graded_questions if num_graded_questions > 0 else 0
    print("-" * 60)
    print(f"  {bcolors.BOLD}Điểm trung bình: {average_score:.2f}%{bcolors.ENDC}")
    print(f"{bcolors.OKBLUE}{'='*60}{bcolors.ENDC}")


def main():
    """Hàm chính để chạy công cụ chấm bài."""
    print(f"{bcolors.BOLD}Bắt đầu quy trình chấm bài tự động...{bcolors.ENDC}")
    
    test_name = input(f"{bcolors.OKCYAN}Nhập tên bài thi cần chấm (ví dụ: Test1, Test2): {bcolors.ENDC}")
    
    testcase_path = os.path.join(EXAM_ROOT_DIR, test_name, "TESTCASE.txt")

    all_test_cases = parse_test_cases(testcase_path)
    if all_test_cases is None:
        return

    if not os.path.isdir(SUBMISSIONS_ROOT_DIR):
        print(f"{bcolors.FAIL}Lỗi: Không tìm thấy thư mục '{SUBMISSIONS_ROOT_DIR}'.{bcolors.ENDC}")
        return

    student_folders = sorted([
        d for d in os.listdir(SUBMISSIONS_ROOT_DIR) 
        if os.path.isdir(os.path.join(SUBMISSIONS_ROOT_DIR, d))
    ])

    if not student_folders:
        print(f"{bcolors.WARNING}Không tìm thấy thư mục sinh viên nào trong '{SUBMISSIONS_ROOT_DIR}'.{bcolors.ENDC}")
        return

    for student_id in student_folders:
        student_scores = grade_student(student_id, all_test_cases)
        display_summary(student_id, student_scores)
    
    print(f"\n{bcolors.BOLD}Quy trình chấm bài đã hoàn tất.{bcolors.ENDC}")


if __name__ == "__main__":
    main()