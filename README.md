# Công Cụ Chấm Bài Tự Động Bằng Python

Công cụ này giúp tự động hóa quá trình chấm bài tập lập trình C. Nó sẽ thực thi file `.exe` của sinh viên, cung cấp dữ liệu đầu vào (input) từ một file test case đã được định nghĩa, và so sánh kết quả đầu ra (output) của chương trình với kết quả mong muốn để tính điểm cuối cùng.

## Yêu cầu Cài đặt
Đảm bảo bạn đã cài đặt **Python phiên bản 3.6 trở lên** trên máy tính của mình. Công cụ này không yêu cầu cài đặt bất kỳ thư viện bên ngoài nào.

## Cấu trúc Thư mục
Công cụ yêu cầu một cấu trúc thư mục cụ thể để hoạt động chính xác.

```
grading_project/          <-- Thư mục gốc của dự án
├── exam/
│   ├── Test1/
│   │   └── TESTCASE.txt  <-- File chứa các ca kiểm thử cho Đề 1
│   └── Test2/
│       └── TESTCASE.txt  <-- File chứa các ca kiểm thử cho Đề 2
│
├── submissions/
│   └── s203055/          <-- Thư mục của một sinh viên (đặt tên bằng MSSV)
│       ├── Q1/
│       │   └── run/
│       │       └── main.exe  <-- File thực thi cần chấm
│       │   └── src/
│       │       └── Q1.c  <-- File code
│       ├── Q2/
│       │   └── ...
│       └── ...
│
└── grading_tool.py         <-- File script Python để chạy công cụ
```

## Định dạng file `TESTCASE.txt`
Tất cả các ca kiểm thử (test case) cho một bài thi phải được đặt trong một file `TESTCASE.txt`. Định dạng của file này rất quan trọng để công cụ có thể đọc và phân tích.

-   Mỗi bộ test case của một câu hỏi bắt đầu bằng một thẻ (tag) như `[Q1]`, `[Q2]`,...
-   Mỗi test case riêng lẻ được phân tách với nhau bằng dấu `---`.
-   Mỗi test case bao gồm một khối `INPUT:` và một khối `EXPECTED_OUTPUT:`.

**Lưu ý quan trọng:** Phần văn bản trong khối `EXPECTED_OUTPUT` chỉ nên chứa kết quả cuối cùng, **không bao gồm** các dòng chữ mời nhập liệu (ví dụ: `Enter n = `). Công cụ được thiết kế để tự động bỏ qua các dòng chữ này và chỉ lấy phần nội dung được in ra sau dòng `OUTPUT:` trong mã nguồn của sinh viên.

**Ví dụ về `TESTCASE.txt`:**
```
[Q1]
INPUT:
25
EXPECTED_OUTPUT:
Yes
---
INPUT:
10
EXPECTED_OUTPUT:
No

[Q2]
INPUT:
5
3 8 1 9 4
EXPECTED_OUTPUT:
Index of largest element: 3
Index of smallest element: 2

[Q3]
...
```

## Cách sử dụng

1.  **Chuẩn bị:** Sắp xếp các thư mục và file theo đúng **Cấu trúc Thư mục** đã mô tả ở trên.
2.  **Mở Terminal:** Mở cửa sổ dòng lệnh (Command Prompt, PowerShell, hoặc Terminal) tại thư mục gốc của dự án (`grading_project/`).
3.  **Chạy Công cụ:** Thực thi câu lệnh sau:
    ```bash
    python grading_tool.py
    ```
4.  **Nhập tên bài thi:** Công cụ sẽ hỏi bạn tên của bài thi muốn chấm.
    ```
    Enter the test name to grade (e.g., Test1, Test2):
    ```
    Bạn hãy nhập tên tương ứng (ví dụ: `Test1`) rồi nhấn `Enter`.

## Xem kết quả
Công cụ sẽ tự động xử lý tất cả các sinh viên trong thư mục `submissions/`. Sau khi chấm xong mỗi sinh viên, một bảng tổng kết điểm sẽ được hiển thị như sau:

```
=============== Final Score Summary for s203055 ===============
  Q1   : 100.00%
  Q2   :  50.00%
  Q3   :   0.00%
  Q4   : NOT GRADED (File not found)
-------------------------------------------------------
  Average Score: 50.00%
=======================================================
```


--------------------------------


# Hướng Dẫn Định Dạng File `TESTCASE.txt`

Tài liệu này mô tả chi tiết cấu trúc và các quy tắc cần tuân thủ khi tạo file `TESTCASE.txt` cho công cụ chấm bài tự động. Việc tuân thủ đúng định dạng là rất quan trọng để đảm bảo công cụ có thể đọc và phân tích các ca kiểm thử một cách chính xác.

## Tổng Quan

File `TESTCASE.txt` là một file văn bản thuần túy (plain text) chứa tất cả các ca kiểm thử (test case) cho một bài thi. Cấu trúc của file được chia thành các cấp như sau:
1.  **Cấp Bài Thi:** Toàn bộ file là một bài thi.
2.  **Cấp Câu Hỏi:** Bài thi được chia thành các khối câu hỏi (ví dụ: `[Q1]`, `[Q2]`).
3.  **Cấp Test Case:** Mỗi câu hỏi lại được chia thành nhiều test case riêng lẻ.

## Các Thành Phần Chính

Một file `TESTCASE.txt` được cấu thành từ 4 thành phần cú pháp chính:

### 1. Thẻ Câu Hỏi (Question Tag)
-   **Cú pháp:** `[Qn]` (ví dụ: `[Q1]`, `[Q2]`)
-   **Mục đích:** Dùng để đánh dấu sự bắt đầu của một bộ test case cho một câu hỏi cụ thể. Tất cả nội dung nằm giữa thẻ này và thẻ tiếp theo (hoặc cuối file) sẽ được coi là thuộc về câu hỏi đó.
-   **Vị trí:** Phải nằm trên một dòng riêng.

### 2. Dấu Phân Tách Test Case (Test Case Separator)
-   **Cú pháp:** `---` (ba dấu gạch ngang)
-   **Mục đích:** Dùng để ngăn cách các test case riêng lẻ *bên trong* một câu hỏi.
-   **Vị trí:** Phải nằm trên một dòng riêng, giữa hai test case.

### 3. Khối Dữ Liệu Vào (Input Block)
-   **Cú pháp:** Bắt đầu bằng từ khóa `INPUT:`
-   **Mục đích:** Chứa toàn bộ dữ liệu sẽ được cung cấp cho đầu vào chuẩn (standard input) của chương trình sinh viên khi chạy test case đó.
-   **Nội dung:** Tất cả các dòng nằm sau `INPUT:` và trước `EXPECTED_OUTPUT:` đều là một phần của dữ liệu vào.

### 4. Khối Kết Quả Mong Muốn (Expected Output Block)
-   **Cú pháp:** Bắt đầu bằng từ khóa `EXPECTED_OUTPUT:`
-   **Mục đích:** Chứa kết quả đầu ra chuẩn (standard output) chính xác mà chương trình của sinh viên phải tạo ra để được tính là đúng.
-   **Nội dung:** Tất cả các dòng nằm sau `EXPECTED_OUTPUT:` và trước dấu phân tách `---` (hoặc thẻ câu hỏi tiếp theo) là một phần của kết quả mong muốn.

## Ví Dụ Hoàn Chỉnh

Dưới đây là một ví dụ minh họa cấu trúc của file, bao gồm 2 câu hỏi, mỗi câu có 2 test case.

```
[Q1]
INPUT:
25
EXPECTED_OUTPUT:
Yes
---
INPUT:
10
EXPECTED_OUTPUT:
No

[Q2]
INPUT:
5
3 8 1 9 4
EXPECTED_OUTPUT:
Index of largest element: 3
Index of smallest element: 2
---
INPUT:
3
-5 -10 -1
EXPECTED_OUTPUT:
Index of largest element: 2
Index of smallest element: 1
```

## Các Quy Tắc Quan Trọng và Lưu Ý

1.  **Chỉ Chứa Kết Quả Cuối Cùng:**
    Phần `EXPECTED_OUTPUT` **chỉ nên chứa kết quả cuối cùng** mà chương trình in ra sau dòng `OUTPUT:`. Không bao gồm các dòng mời nhập liệu như `Enter n = ` hay `Nhap mot so nguyen:`.

    -   **ĐÚNG:**
        ```
        EXPECTED_OUTPUT:
        Yes
        ```
    -   **SAI:**
        ```
        EXPECTED_OUTPUT:
        Enter n = 25
        OUTPUT:
        Yes
        ```

2.  **Dữ liệu Nhiều Dòng:**
    Cả `INPUT` và `EXPECTED_OUTPUT` đều hỗ trợ nội dung trên nhiều dòng. Chỉ cần viết nội dung trên các dòng liên tiếp nhau như trong ví dụ của `[Q2]`.

3.  **Khoảng Trắng và Dòng Trống:**
    Công cụ được thiết kế để tự động loại bỏ các khoảng trắng thừa ở đầu và cuối mỗi dòng, cũng như các dòng trống. Do đó, bạn không cần quá lo lắng về việc thụt lề hay có các dòng trống trong khối `INPUT` và `EXPECTED_OUTPUT`, miễn là nội dung và thứ tự các dòng không trống là chính xác.

4.  **Encoding File:**
    Để đảm bảo tính tương thích, đặc biệt khi có thể có ký tự tiếng Việt, hãy lưu file `TESTCASE.txt` với bảng mã **UTF-8**.

5.  **Thứ Tự:**
    Thứ tự của các khối câu hỏi (`[Q1]`, `[Q2]`,...) trong file không quan trọng. Tuy nhiên, để dễ quản lý, bạn nên sắp xếp chúng theo thứ tự.

6.  **Tính Linh Hoạt:**
    Bạn có thể có các dòng trống giữa dấu phân tách `---` và khối `INPUT:` tiếp theo, hoặc giữa một test case và một thẻ câu hỏi mới. Công cụ sẽ bỏ qua chúng.