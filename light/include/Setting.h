const char *SETTING =R"=====(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Light control</title>
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
    </style>
</head>

<body>
    <div>
        <div class="header">
            Control panel
        </div>
        <div class="pagination">
            <a href="./index.html">Static mode</a>
            <a href="#">Animated mode</a>
            <a href="#" class="active">Setting</a>
        </div>
        <div>
            <h1 class="contain">Setting</h1>

            <p><input type="range" onchange="updatelight(this)" id="lightSlider" min="0" max="255"
                    value="%BRIGHTVALUE%" step="1" class="slider">

        </div>
    </div>

    <script>
        function updatelight(element) {
            var sliderValue = document.getElementById("lightSlider").value;
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/ChangeBright?value=" + sliderValue, true);
            xhr.send();
        }
    </script>
</body>


</html>)=====";