<center>

# Problem 3: Tổng lớn nhất

Time limit: $4.0s$ $|$ Memory limit: $1024M$

</center>

---

Hải có một dãy số nguyên $a_1, a_2, \dots, a_n$. Cô muốn tìm một đoạn con liên tiếp (có thể không chứa phần tử nào) của dãy $a$ mà có tổng lớn nhất.

Nhắc lại, một dãy $b$ được gọi là đoạn con liên tiếp của $a$ khi và chỉ khi có thể thu được $b$ từ $a$ bằng cách xóa đi một số phần tử đầu tiên và cuối cùng của dãy $a$. Ví dụ, $(2, 3, 4)$ và $(1, 2, 3)$ là các đoạn con của $(1, 2, 3, 4, 5)$, trong khi $(1, 3, 4)$ thì không.

Sau khi tìm được dãy con thỏa mãn, Hải thấy dãy vừa rồi có tổng không đủ lớn nên cô quyết định tạo thêm một dãy số $m_1, m_2, \dots, m_k$. Với mỗi giá trị $m_i$, cô có thể chọn tối đa một đoạn con liên tiếp của $a$ và nhân giá trị các phần tử trong đoạn với $m_i$. Sau khi thực hiện thao tác với toàn bộ dãy $m$, Hải sẽ tìm đoạn con có tổng lớn nhất của dãy $a$ và tính tổng các phần tử trong đoạn con này.

Do số cách thực hiện thao tác là quá lớn, Hải đã nhờ Hoàng tìm cách thực hiện sao cho kết quả cuối cùng thu được là lớn nhất. Vũ cũng cảm thấy bài toán này quá khó nên anh cần các bạn giúp anh giải quyết nó.

Yêu cầu: Hãy giúp Hoàng tìm một cách thực hiện các thao tác nhân sao cho tổng cuối cùng
thu được là lớn nhất.

## Dữ liệu:

- Dòng đầu tiên gồm hai số nguyên dương $n, k$ $(1 \le n \le 10^5, 1 \le k \le 6)$.
- Dòng tiếp theo gồm $n$ số nguyên $a_1, a_2, \dots, a_n$ $(|a_i| \le 1000)$.
- Dòng tiếp theo gồm $k$ số nguyên $m_1, m_2, \dots, m_k$ $(|m_i| \le 50)$.

## Kết quả:

- Dòng đầu tiên là tổng cuối cùng tối đa tìm được.
- $k$ dòng tiếp theo, dòng thứ $i$ gồm hai số nguyên $u_i, v_i$ mô tả thao tác của Hải đổi với $m_i$:
    - Nếu $u_i = v_i = 0$, Hải sẽ bỏ qua số $m_i$.
    - Ngược lại, Hải sẽ chọn đoạn con liên tiếp $(u_i, v_i)$ lên $m_i$. Hiển nhiên điều kiện hợp lệ là $1 \le u_i \le v_i \le n$.
- Dòng cuối cùng gồm hai số nguyên dương $l, r$ $-$ Hà sẽ tính tổng các số trong đoạn $(l, r)$. Nếu chọn đoạn rỗng, $l = r = 0$.
- Nếu có nhiều cách thực hiện thao tác cùng cho ra kết quả tối ưu, in ra một cách bất kỳ.

## Chấm điểm

| Điểm (%) | Ràng buộc bổ sung |
|------|-------------------|
| $20\%$ | $n \le 300$ và $k=1$. |
| $20\%$ | $k=1$. |
| $15\%$ | $m_i > 0$ với mọi $i$. |
| $15\%$ | $m_i = m_2 = \dots = m_k$. |
| $10\%$ | $k \le 3$. |
| $10\%$ | $k \le 4$.|
| $10\%$ | Không có ràng buộc gì thêm. |

## Ví dụ

### Input
```
5 3
1 2 3 -4 -5
-1 -3 4
```

### Output
```
180
1 3
1 5
1 5
1 5
```

### Giải thích

* Với $m_1 = -1$, Hà có thể chọn đoạn $(1, 3)$.
Dãy sau khi thực hiện thao tác là $[-1, -2, -3, 4, 5]$.

* Với $m_2 = -3$, Hà có thể chọn đoạn $(1, 5)$.
Dãy sau khi thực hiện thao tác là $[3, 6, 9, 12, 15]$.

* Với $m_3 = 4$, Hà có thể chọn đoạn $(1, 5)$.
Dãy sau khi thực hiện thao tác là $[12, 24, 36, 48, 60]$.

* Đoạn con có tổng lớn nhất của dãy là đoạn $(1, 5)$, với tổng là $12 + 24 + 36 + 48 + 60 = 180$.

$\to$ Có thể nhận thấy rằng đây là cách thực hiện tối ưu nhất.