BÀI TẬP LỚN MÔN LẬP TRÌNH NÂNG CAO

Họ và tên: Nguyễn Minh Quân
MSV: 21020383
Nhóm 6 lớp INT2215_1

Game của em tên là Flying Helicopter, là 1 game đơn giản điều khiển trực thăng bay né tránh các trở ngại (là các máy bay trực thăng khác)
1) Cách cài đặt:
  - Trước tiên cần cài đặt trình biên dịch MinGW (xem hướng dẫn tại: https://azrael.digipen.edu/~mmead/www/public/mingw/#64BIT)
  - tải file game.rar về và giải nén được thư mục game
  - mở thử mục game, ấn shift + chuột phải và chọn mở terminal tại đây
  - nhập dòng lệnh :mingw32-make để build chương trình
  - nhấp vào file game.exe để chạy chương 
 
 
 2) Giới thiệu chung:
  Đây là 1 game điều khiển máy bay trực thăng theo phương thẳng đứng. Bằng cách ấn phím cách (space) hoặc phím mũi tên hướng lên (up), ta có thể lái trực thăng bay lên   1 đoạn thẳng. Game được lấy ý tưởng từ game Flappy bird và các game điều khiển trực thăng, ý tưởng ban đầu của em là tạo ra 1 game chạy vô tận với độ khó tăng 
  - các nguồn tham khảo:
  https://phattrienphanmem123az.com/lap-trinh-game-cpp
  https://www.youtube.com/playlist?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS
  
  
 3) Các chức năng đã cài đặt:
  + Trực thăng chính
    - Đây là máy bay của người chơi điều khiển. máy bay sẽ tự động giảm độ cao (sau 2s khi game bắt đầu), có thể tăng độ cao của máy bay bằng cách ấn phím cách (space)    hoặc phím mũi tên hướng lên (up). Vị trí bắt đầu là phía trên bên trái 
    - Khi va chạm với máy bay trở ngại thì sẽ kết thúc trò chơi (Game over), có thể ấn space để chơi lại hoặc esc để thoát.
  
  + Trực thăng trở ngại
    - Đây là kẻ địch chính của trò chơi, Các máy bay này có thể xuất hiện ngẫu nhiên để cản trở trực thăng của người chơi
    - các máy bay xuất hiện cách nhau 2s

  + Hệ thống điểm (score) và cấp bậc (level)
    - Người chơi sẽ bắt đầu ở 0 điểm và level 1
    - Trực thăng chính mỗi khi né tránh được 1 trực thăng trở ngại thì sẽ được 1 điểm, cứ mỗi 5 điểm có được sẽ tăng 1 level, khi tăng level sẽ tăng tốc độ của trực      thăng trở ngại. Có tối đa 5 level.

  + Video minh họa: https://youtu.be/kgKIHLS5XAU


  4) Các kỹ thuật lập trình được sử dụng trong chương trình: 
  + Các cấu trúc lặp (for, while)
  + Con trỏ, vector, sinh số ngẫu nhiên
  + Lớp
  + Đồ họa SDL2, thư viện SDL_image


  5) Kết luận: 
    Vì thời gian tiếp xúc với lập trình chưa nhiều nên chương trình của em còn rất nhiều thiếu sót và vẫn có thể phát triển nhiều hơn nữa, em còn rất nhiều ý tưởng cho   game như hiển thị số điểm và level, thêm tính năng máu(hp), thêm các item để tăng điểm, tăng các chỉ số tốc độ, đã dạng các loại chướng ngại, thêm âm thanh.....
    trong suốt thời gian học và hoàn thiện chương trình này em rút ra rất nhiều bài học, bản thân em thấy rằng vẫn còn nhiều phần còn chưa nắm vững và cần luyện tập     thêm. 
    Em rất cảm ơn các thầy đã hỗ trợ để em có thể hoàn thành chương trình này.
