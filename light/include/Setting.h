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
          <h1>ESP32 Status</h1>
          <p>
            <b>WiFi Connection:</b> 
            <?php if (WiFi.status() == WL_CONNECTED): ?>
              Connected to <span style="color:green;"><?php echo WiFi.SSID(); ?></span>
            <?php else: ?>
              Disconnected
            <?php endif; ?>
          </p>
          <p>
            <b>Free Heap:</b> <?php echo ESP.getFreeHeap(); ?> bytes
          </p>

    <script>
    </script>
</body>


</html>)=====";