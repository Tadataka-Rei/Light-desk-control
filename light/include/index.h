const char *index_html = R"=====(<!DOCTYPE html>
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
            <a href="#">Static mode</a>
            <a href="#">Animated mode</a>
            <a href="#" class="active">Setting</a>
        </div>
        <div>
            <h1 class="contain"> Static light</h1>


            %PLACEHOLDER%
        </div>
    </div>
</body>
<script>
    const colorInput = document.querySelector('input[type="color"]');

    colorInput.addEventListener('change', (event) => {
        const selectedColor = event.target.value;
        const placeholderElement = document.querySelector('.contain');
        placeholderElement.textContent = `Selected Color: ${selectedColor}`;
    });
</script>

</html>)=====";