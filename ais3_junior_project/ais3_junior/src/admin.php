<?php

if($_COOKIE['pass']!=="serdesfsefhijosefjtfgyuhjiosefdfthgyjh"){
  header('Location: index.php');
  exit();
}
?>

<html>
    <head>
	<link href="https://fonts.googleapis.com/css?family=IBM+Plex+Sans" rel="stylesheet"> 
	<link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
	<div class="menu">
	    <a href="admin.php">Main Page</a>
	    <a href="admin.php?view=about-us.html">About Us</a>
	</div>
<?php

if(!isset($_GET['view']) || ($_GET['view']=="admin.php")) {
   echo" <p><b>Welcome to our main page!</b><br><br>login sccess!!!</br></p>
    <img src='https://i.imgur.com/s9K655G.jpeg'>";
}
else {
	echo "<p>";
	include("/var/www/html/" .$_GET['view']);
	echo "</p>";
}
?>
    </body>
</html>
