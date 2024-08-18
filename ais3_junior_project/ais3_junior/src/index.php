<?php
error_reporting(0);
error_reporting(E_ALL & ~E_WARNING);
$pass = "serdesfsefhijosefjtfgyuhjiosefdfthgyjh";

if (isset($_GET['login']) && $_GET['login'] === "1") {
if (strcmp($_POST['username'], "admin") == 0 && strcmp($_POST['password'], $pass) == 0) {
    setcookie('pass', $pass, time() + 365*24*3600);
    echo "<div class='success'>Welcome! </br> Go to the <a href=\"admin.php\">admin</a></div>";
} else {
    echo "<div class='error'><p>Bad user/password!</br>Return to the <a href=\"index.php\">login page</a></p></div>";
}
exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Page</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }
        .container {
            background-color: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
            width: 300px;
            text-align: center;
        }
        h1 {
            color: #333;
            margin-bottom: 20px;
        }
        label {
            display: block;
            margin: 10px 0 5px;
            color: #666;
        }
        input[type="text"], input[type="password"] {
            width: 100%;
            padding: 10px;
            margin-bottom: 10px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        input[type="submit"] {
            background-color: #4CAF50;
            color: white;
            padding: 10px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            width: 100%;
        }
        input[type="submit"]:hover {
            background-color: #45a049;
        }
        .error, .success {
            color: white;
            padding: 10px;
            margin: 10px 0;
            border-radius: 4px;
        }
        .error {
            background-color: #f44336;
        }
        .success {
            background-color: #4CAF50;
        }
        a {
            color: #000000;
            text-decoration: none;
        }
        a:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>

<div class="container">

    <form action="index.php?login=1" method="POST">
        <h1>Login</h1>
        <label><b>User:</b></label>
        <input type="text" name="username" required>
        <label><b>Password:</b></label>
        <input type="password" name="password" required>
        <input type="submit" id='submit' value='Login'>
    </form>
</div>

</body>
</html>
