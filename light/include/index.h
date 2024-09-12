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
                <br/>
                <input type="color" value="%COLORS%" id="ColorInput" style="width:85%;">
            </br>
                Start pos:<input type="number" id="StartInput" min="0" max="%LEDNUM%">
            </br>
                End pos:<input type="number" id="EndInput" min="0" max="%LEDNUM%">
            </br>
                <button onclick="Change()" >Change</button>


        <script>
            function Change()
                {
                    
                    var xhr = new XMLHttpRequest();
                    xhr.open("GET", "/static?Start="+document.getElementById("StartInput").value+"&End="+document.getElementById("EndInput").value+"Color="+document.getElementById("ColorInput").value, true);
                    xhr.send();
                }
        </script>
</body>

</html>)=====";