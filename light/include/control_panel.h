const char Control_panel_html[] PROGMEM = R"=====(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Document</title>
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
    .contain {
      margin-left: 20px;
    }
    input {
      position: absolute;
      top: 150px;
      width: 400px;
      height: 25px;
      border: 1px solid rgba(112, 108, 108, 0.589);
      border-radius: 5px;
    }
    table {
      margin-top: 20px;
      border-collapse: collapse;
      width: 700wb;
    }
  </style>
</head>
<body>
  <div>
    <div>
      <ul>
        <li><a href="index.html">Trang chủ</a></li>
        <li><a href="#">Bảng điều khiển</a></li>
      </ul>
    </div>
    <div class="contain">
      <h1>Bảng điều khiển</h1>
      <input type="text" placeholder="Start typing" />
      <br />
      <table>
        <tr>
          <th>Unit</th>
          <th>Location</th>
          <th>Status</th>
          <th>Last cleaned</th>
        </tr>
        %PLACEHOLDER%
      </table>
    </div>
  </div>
</body>
</html>)=====";