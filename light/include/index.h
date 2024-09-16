const char *index_html = R"=====(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Static light</title>
    <style>
        body {
            background-color: #ffffff;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        .header {
            padding: 4vw;
            overflow: hidden;
            background-color: #001aff;
            display: flex;
            justify-content: center;
            color: white;
            font-size: 5vh;
        }

        .pagination {
            display: flex;
            justify-content: center;
        }

        .pagination a {
            color: black;
            float: left;
            padding: 1vh 6vw;
            text-decoration: none;
            border: 1px solid #ddd;
        }

        .pagination a.active {
            background-color: #9265fa;
        }

        input {
            height: 5vh;

        }
    </style>
</head>

<body>

    <div>
        <div class="header">
            Control panel
        </div>
        <div class="pagination">
            <a href="#" class="active">Static mode</a>
            <a href="#">Animated mode</a>
            <a href="./Setting.html">Setting</a>
        </div>
        <h1>Static mode control panel</h1>
        <br />
        <br />
        <input type="color"  id="ColorInput" value="%COLORS%" style="width:85vw;">
        <button onclick="ChangeColor()">Change COLOR</button>
        </br>
        Start pos:<input type="number"  id="StartInput" min="0" max="%LEDNUM%" value="%Spos%">
        </br>
        End pos:<input type="number" id="EndInput" min="0" max="%LEDNUM%" value="%Epos%">
        </br>
        <button onclick="Changepos()">Change POS</button>


        <script>
            function Changepos() {
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/changepos?S=" + document.getElementById("StartInput").value + "&E=" + document.getElementById("EndInput").value, true);
                xhr.send();
            }
            
            function ChangeColor() {
                var hex = document.getElementById("ColorInput").value;
                hex = hex.replace('#', '');

                var xhr = new XMLHttpRequest();
                xhr.open("GET","/changecolor?color=" + hex , true);
                xhr.send();
            }
        </script>
</body>

</html>)=====";