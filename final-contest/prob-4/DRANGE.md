<center>

# Problem 4: Xóa đoạn

Time limit: $1.0s$ $|$ Memory limit: $256M$

</center>

---

Hải gọi một dãy số là một khối nếu dãy số đó có độ dài là $k+1$, và phần tử đầu tiên của dãy là $k$ ($k$ có thể là số nguyên dương bất kỳ).

Ví dụ, $(2,1,2)$ hoặc $(1,2)$ là một khối, tuy nhiên $(2,1)$ không phải một khối.

Hải gọi một dãy số là đẹp nếu có thể tồn tại một cách lặp lại các thao tác dưới đây cho đến khi dãy trở thành dãy rỗng (không còn phần tử nào):
- Chọn một đoạn con liên tiếp trong dãy sao cho đoạn con được chọn là một khối.
- Xóa đoạn con được chọn khỏi dãy và dồn các phần tử phía sau lên trước.

Ví dụ, $(1,2,1,2,1,4,4)$ là một dãy đẹp vì có thể xóa dãy như sau:
- Chọn đoạn $(1,2)$ bắt đầu ở vị trí $3$. Hiển nhiên đoạn này là một khối. Xóa đoạn khỏi dãy. Dãy trở thành $(1,2,1,4,4)$.
- Chọn đoạn $(2,1,4)$ bắt đầu ở vị trí $2$. Hiển nhiên đoạn này là một khối. Xóa đoạn khỏi dãy. Dãy trở thành $(1,4)$.
- Chọn đoạn $(1,4)$ bắt đầu ở vị trí $1$. Hiển nhiên đoạn này là một khối. Xóa đoạn này và dãy trở thành dãy rỗng.

Hải đưa cho Hoàng một dãy $a_1, a_2, \dots, a_n$. Cô đố Hoàng đếm xem có bao nhiêu đoạn con liên tiếp của dãy $a$ là dãy đẹp. Tuy nhiên Hoàng còn bận làm một số việc khác nên không chưa thể trả lời câu hỏi này. Bạn hãy trả lời giúp Hoàng nhé.

*Đoạn con liên tiếp là một đoạn con thu được bằng cách xóa không, một hoặc một vài phần tử ở đầu và cuối dãy và giữ nguyên thứ tự các phần tử còn lại. Ví dụ, $(3, 4), (3, 4, 5)$ hay $(1)$ đều là các đoạn con liên tiếp của $(1, 2, 3, 4, 5)$ nhưng $(1, 3)$ hay $(3, 2)$ thì không. Đoạn con liên tiếp gồm các phần tử ở vị trí thứ $l$ đến vị trí thứ $r$ có thể được gọi là đoạn $(l, r)$.*

## Dữ liệu:

- Dòng đầu tiên gồm một số nguyên dương $n$ $(1 \le n \le 7000)$.
- Dòng tiếp theo gồm $n$ số nguyên dương $a_1, a_2, ..., a_n$ $(1 \le a_i \le n)$.

## Kết quả:

- Một dòng duy nhất gồm số lượng đoạn con liên tiếp của dãy $a$ là dãy đẹp.

## Chấm điểm

| Điểm | Ràng buộc bổ sung |
|------|-------------------|
| $4\%$ | $n \le 5$ |
| $8\%$ | $n \le 20$ |
| $12\%$ | $n \le 500,a_i \in \{1, n\}$ |
| $12\%$ | $n \le 500$ |
| $20\%$ | $a_i \in \{1, n\}$ |
| $16\%$ | $n \le 2000$ |
| $28\%$ | Không có ràng buộc gì thêm |

## Ví dụ

### Input
```
5
1 2 1 2 4
```

### Output
```
5
```

### Giải thích

* Các đoạn $(l, r)$ là đoạn đẹp trong dãy là: $(1,2),(2,4),(3,4),(1,4),(1,5)$.