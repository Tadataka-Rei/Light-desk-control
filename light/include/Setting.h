const char *SETTING =R"=====(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Light control</title>
    <style>
        body {
            font-family: Arial, sans-serif;
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
            display: inline-block;
            display: flex;
            justify-content: center;
        }

        .pagination a {
            color: black;
            float: left;
            padding: 1vh 6vw;
            text-decoration: none;
            transition: background-color .3s;
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
            <a href="#" class="active">Static mode</a>
            <a href="#">Animated mode</a>
            <a href="#">Setting</a>
        </div>
        <div>
            <h1 class="contain">Setting</h1>

            <p><span id="textSliderValue">%BRIGHTNESS%</span></p>
            <p><input type="range" onchange="updateSliderPWM(this)" id="pwmSlider" min="0" max="255"
                    value="%BRIGHTNESS%" step="1" class="slider"></p>
            %PLACEHOLDER%
        </div>
    </div>

    <script>
        function updateSliderPWM(element) {
            var sliderValue = document.getElementById("pwmSlider").value;
            document.getElementById("textSliderValue").innerHTML = sliderValue;
            console.log(sliderValue);
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/slider?value=" + sliderValue, true);
            xhr.send();
        }
    </script>
</body>


</html>)=====";