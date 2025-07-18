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


------------------------


# Hướng Dẫn Làm Bài Tập Lập Trình C

## Lời Giới Thiệu

Chào mừng bạn đến với bài tập lập trình C! Tài liệu này sẽ hướng dẫn bạn cách hoàn thành các bài toán bằng cách sử dụng các file mẫu đã được cung cấp (`Q1.c`, `Q2.c`, v.v.).

Mục đích của định dạng này là để giúp bạn **tập trung vào logic giải quyết vấn đề cốt lõi (thuật toán)** thay vì phải viết các đoạn mã lặp đi lặp lại để đọc dữ liệu đầu vào và in kết quả. Mỗi file được cấu trúc thành hai phần chính:

1.  **Hàm Cần Hoàn Thiện**: Đây là một hàm cụ thể nơi bạn sẽ viết toàn bộ mã nguồn của mình. Vị trí này được đánh dấu rõ ràng bằng các dòng chú thích `// VIẾT MÃ CỦA BẠN VÀO ĐÂY` và `// KẾT THÚC PHẦN MÃ CỦA BẠN`.
2.  **Hàm `main`**: Hàm này đã được **khóa cố định** và được sử dụng để kiểm tra và chấm điểm. Nó sẽ xử lý việc đọc dữ liệu, gọi hàm của bạn và in kết quả theo một định dạng chuẩn.

### Quy Tắc Vàng
**KHÔNG, trong bất kỳ trường hợp nào, được sửa đổi hàm `main` hoặc bất kỳ đoạn mã nào nằm ngoài khối được chỉ định.** Mọi thay đổi có thể khiến công cụ chấm bài tự động chấm sai bài của bạn, ngay cả khi logic của bạn đúng.

---

## Bài toán 1: Q1.c - Kiểm Tra Số Chính Phương

### Đề bài
Nhiệm vụ của bạn là viết một hàm để xác định xem một số nguyên `n` cho trước có phải là số chính phương hay không. Một số chính phương là một số nguyên bằng bình phương của một số nguyên khác (ví dụ: 9 là số chính phương vì 3 * 3 = 9).

### Nhiệm vụ của bạn trong `Q1.c`
Bạn phải hoàn thành hàm `is_perfect_square`.

```c
int is_perfect_square(int n) {
    // VIẾT MÃ CỦA BẠN VÀO ĐÂY

    // Logic của bạn được viết ở đây.
    // Bạn phải trả về 1 nếu n là số chính phương.
    // Bạn phải trả về 0 nếu n không phải là số chính phương.

    // KẾT THÚC PHẦN MÃ CỦA BẠN
}
```

-   **Đầu vào**: Hàm nhận một số nguyên `n`.
-   **Đầu ra**: Hàm phải `return` một số nguyên: `1` nếu là số chính phương ("Yes") và `0` nếu không phải ("No").

**Cách Hoạt Động:** Hàm `main` sẽ đọc một số từ người dùng, truyền nó vào hàm `is_perfect_square` của bạn, và sau đó in ra "Yes" hoặc "No" dựa trên giá trị `1` hoặc `0` mà hàm của bạn trả về.

---

## Bài toán 2: Q2.c - Tìm Vị Trí Nhỏ Nhất và Lớn Nhất

### Đề bài
Nhiệm vụ của bạn là tìm chỉ số (bắt đầu từ 0) của phần tử nhỏ nhất và lớn nhất trong một mảng số nguyên cho trước. Nếu có nhiều phần tử cùng đạt giá trị nhỏ nhất/lớn nhất, chỉ cần lấy chỉ số của phần tử xuất hiện đầu tiên.

### Nhiệm vụ của bạn trong `Q2.c`
Bạn phải hoàn thành hàm `find_min_max_indices`. Hàm này đặc biệt vì nó không trả về giá trị. Thay vào đó, nó sử dụng **con trỏ** để sửa đổi trực tiếp các biến trong hàm `main`.

```c
void find_min_max_indices(int arr[], int n, int *min_idx, int *max_idx) {
    // VIẾT MÃ CỦA BẠN VÀO ĐÂY

    // Logic của bạn được viết ở đây.
    // Bạn cần tìm các chỉ số chính xác và gán chúng.
    // Ví dụ: *min_idx = mot_chi_so_nao_do;
    //       *max_idx = mot_chi_so_khac;

    // KẾT THÚC PHẦN MÃ CỦA BẠN
}
```

-   **Đầu vào**: Hàm nhận mảng `arr`, kích thước `n` của mảng, và hai con trỏ `min_idx` và `max_idx`.
-   **Nhiệm vụ**: Mã của bạn phải tìm các chỉ số chính xác và cập nhật giá trị tại các địa chỉ bộ nhớ mà `min_idx` và `max_idx` đang trỏ tới.

**Cách Hoạt Động:** Hàm `main` đọc dữ liệu mảng, sau đó gọi hàm của bạn và truyền địa chỉ của hai biến `min_index` và `max_index` của nó. Các cập nhật của hàm bạn sẽ được phản ánh trong `main`, và `main` sẽ in ra kết quả cuối cùng.

---

## Bài toán 3: Q3.c - Tính Tổng Có Điều Kiện

### Đề bài
Nhiệm vụ của bạn là tính tổng các phần tử trong một mảng số nguyên dựa trên một điều kiện:
-   Nếu **phần tử đầu tiên** của mảng là một số nguyên tố, hãy tính và trả về tổng của tất cả các số **chẵn** trong mảng.
-   Nếu **phần tử đầu tiên** không phải là số nguyên tố, hãy tính và trả về tổng của tất cả các số **lẻ** trong mảng.

### Nhiệm vụ của bạn trong `Q3.c`
Bạn phải hoàn thành hàm `calculate_conditional_sum`.

```c
long long calculate_conditional_sum(int arr[], int n) {
    // VIẾT MÃ CỦA BẠN VÀO ĐÂY

    // Logic của bạn được viết ở đây.
    // 1. Kiểm tra xem arr có phải là số nguyên tố không.
    // 2. Dựa vào kết quả kiểm tra, duyệt qua mảng và tính tổng tương ứng.
    // 3. Trả về tổng cuối cùng.

    // KẾT THÚC PHẦN MÃ CỦA BẠN
}
```

-   **Đầu vào**: Hàm nhận mảng `arr` và kích thước `n` của mảng.
-   **Đầu ra**: Hàm phải `return` tổng đã tính dưới dạng `long long` để tránh khả năng bị tràn số.

**Cách Hoạt Động:** Hàm `main` đọc dữ liệu mảng, truyền nó vào hàm của bạn, và sau đó in ra giá trị `long long` duy nhất mà hàm của bạn trả về.

---

## Bài toán 4: Q4.c - Tìm Ngày và Tháng Kế Tiếp

### Đề bài
Nhiệm vụ của bạn là tính toán ngày và tháng của ngày kế tiếp. Lịch được đơn giản hóa: **Tháng 2 luôn có 28 ngày**, và năm được bỏ qua (ngày sau ngày 31/12 là ngày 01/01).

### Nhiệm vụ của bạn trong `Q4.c`
Bạn phải hoàn thành hàm `find_next_day`. Tương tự như Q2, hàm này sử dụng con trỏ để sửa đổi các biến trong `main`.

```c
void find_next_day(int *day, int *month) {
    // VIẾT MÃ CỦA BẠN VÀO ĐÂY

    // Logic của bạn được viết ở đây.
    // Bạn cần tăng ngày và tháng một cách chính xác.
    // Hãy nhớ xử lý các trường hợp chuyển tháng (ví dụ: từ 30/04 sang 01/05)
    // và trường hợp cuối năm (từ 31/12 sang 01/01).
    // Sử dụng (*day) và (*month) để truy cập và sửa đổi giá trị.
    // Ví dụ: (*day)++;

    // KẾT THÚC PHẦN MÃ CỦA BẠN
}
```

-   **Đầu vào**: Hàm nhận con trỏ tới các biến `day` và `month`.
-   **Nhiệm vụ**: Mã của bạn phải cập nhật các giá trị tại các địa chỉ bộ nhớ này thành ngày kế tiếp.

**Cách Hoạt Động:** Hàm `main` đọc một ngày và tháng, truyền địa chỉ của chúng vào hàm của bạn, và sau đó in ra các giá trị mới sau khi hàm của bạn đã sửa đổi chúng.

## Lời Nhắc Cuối Cùng
-   **Tập trung vào logic** bên trong hàm được chỉ định cho bạn.
-   Không tự viết các lệnh `printf` hay `scanf` bên trong hàm mà bạn đang hoàn thiện.
-   Không thay đổi định nghĩa của hàm (tên, tham số, hoặc kiểu trả về).
-   Kiểm tra logic của bạn cẩn thận trước khi nộp bài. Chúc may mắn!