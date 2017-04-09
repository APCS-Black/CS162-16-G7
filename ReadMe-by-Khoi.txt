[Update: SMS.h , Lecturer.cpp , Lecturer.h ]
(Nhớ bổ sung HeaderList.h)
- Tui đã add note vào tất cả các file; chỉnh biến Class trong SMS.h; 
chỉnh lại vài lỗi code trong Lecturer.cpp;
add hàm clear_screen() (dùng cho phần menu) 
và hàm UpdateLecturerClass vào Lecturer.cpp/.h
(theo yêu cầu của Nghị, khi Academic Staff tạo course mới,
lecturer tương ứng sẽ được cập nhật course đó vào biến char** Class của tài khoản User,
cách dùng sẽ nói rõ ở cuối file này)

[New: UserList.cpp/.h , Menu.cpp/.h]
- Xog UserList, cách tạo và sử dụng khá tương tự CourseList
Data File: Users.txt 
- Menu.cpp/.h:
+ Tui chia ra thành nhiều menu (đọc note trong các file trc khi đọc tiếp), 
để ý là đây chỉ là sườn, và ở hàm main mình sẽ tạo hết mọi object và biến v.v..
rồi gọi hàm MenuIntro ở Menu.h và truyền ~ thứ cần thiết vào hàm MenuIntro, 
các menu khác dc code nằm trong MenuIntro và menu nào cần cái gì thì truyền vào cái đó 
(thay đổi parameter của các hàm menu cho phù hợp, parameter có sẵn chỉ là minh họa)
(sửa và bổ sung code thẳng vào Menu.cpp/.h, ai code phần nào thì chỉnh menu phần đó)
+ Sở dĩ chia ra như vậy vì nếu dồn hết lại vào hàm main thì nó sẽ thành 1 cục rất gớm,
, dài, thiếu hệ thống, khó xem, v.v..; và việc truyền parameter ko nhiều lắm nên cũng ko ảnh hưởng 
lớn tới speed, giống như là mình chia code ra thành các block vậy thui

[Msg to Nghị]
1. Lecturer.cpp/.h chỉ còn cần update 2 biến int this_year, this_semester 
trong hàm ImportScore.
+ this_semester như tui đã nói cách thì ông tìm 1 course nào đó trong courselist end date
chưa expired so với date hiện tại rồi lấy cái semester của course đó thì sẽ dc
semester hiện tại (sẽ luôn tồn tại course có semester hiện tại vì nếu ko thì ko có lecturer)
+ Tui thấy ông nên lưu biến semester và year hiện tại trong class courselist để dễ dùng

2. Cách dùng hàm UpdateLecturerClass ở trên:
- Trong hàm void g_CourseList::Import khi nhập tới Lecturerusername,
ông dùng hàm FindUser của class UserList để tìm ra dc User đó, 
rồi gọi hàm UpdateLecturerClass với User tìm được thì nó sẽ update biến char** Class 
trong tài khoản/class User của lecturer đó
+ Nhớ là phải check thêm năm và học kỳ hiện hành của course trc khi cập nhật course cho lecturer

3. Bây giờ dm hơn 3 rưỡi sáng, chắc trưa mai tui mới onl , so so... :)