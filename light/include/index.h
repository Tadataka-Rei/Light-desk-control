const char *index_html = R"=====(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>indexpage</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #f4f4f4;
      align-items: center;
      height: 100vh;
      margin: 0;
    }
    ul {
      list-style-type: none;
      margin: 0;
      padding: 0;
      overflow: hidden;
      background-color: #0d9c68;
      display: flex;
      justify-content: center;
    }
    li {
      padding: 4vw;
    }
    li:hover {
      background-color: blue;
    }
    a {
      text-decoration: none;
      color: white;
      font-size: 5vh;
    }
    section {
      text-align: center;
      margin-top: 200px;
    }
  </style>
</head>
<body>
  <div>
    <div>
      <ul>
        <li><a href="#">Trang chủ</a></li>
        <li><a href="login.html">Bảng điều khiển</a></li>
      </ul>
    </div>
    <section>
      <h2>Trang chủ<br> Thùng rác thông minh</h2>
      <p>
        Đây là trang chủ điều khiển thùng rác thông minh của bạn.
        <br> vui lòng đăng nhập để xác thực
      </p>
      <a href="login.html"> <button> Đăng nhập </button></a>
    </section>
  </div>
</body>
</html>)=====";