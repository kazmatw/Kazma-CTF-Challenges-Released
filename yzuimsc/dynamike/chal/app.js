const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 3000;

const _database = {
    "users": [
        {
            "username": "admin",
            "password": "cf9ee5bcb36b4936dd7064ee9b2f139e"
        }
    ]
};

app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Nothing here</title>
    </head>
    <body>
      <h1>Hello, hackers.</h1>
      <p>I have split the flag into two parts and hidden them somewhere on this website.</p>
      <p>Can you find the flag?</p>
    </body>
    </html>
  `);
});

app.get('/_data', (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Flag Found</title>
    </head>
    <body>
      <h1>Congratulations!</h1>
      <p>}3k1l-d0g_3r4_u0y :galf eht fo trap dnoces eht dnuof ev'uoY</p>
    </body>
    </html>
  `);
});

app.get('/login', (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Login</title>
    </head>
    <body>
      <h1>Login Page</h1>
      <form action="/login" method="post">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username"><br><br>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password"><br><br>
        <input type="submit" value="Login">
      </form>
    </body>
    </html>
  `);
});

app.post('/login', (req, res) => {
  const { username, password } = req.body;

  if (username === 'admin' && password === 'naruto') {
    res.send(`
      <!DOCTYPE html>
      <html lang="en">
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Login Success</title>
      </head>
      <body>
        <h1>Login Successful!</h1>
        <p>_31dr1b_31dr1b_31dr1b{CSMIUZY :galf eht fo trap tsrif eht dnuof ev'uoY</p>
      </body>
      </html>
    `);
  } else {
    res.send(`
      <!DOCTYPE html>
      <html lang="en">
      <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Login Failed</title>
      </head>
      <body>
        <h1>Login Failed</h1>
        <p>Invalid username or password. Please try again.</p>
        <a href="/login">Back to login</a>
      </body>
      </html>
    `);
  }
});

app.get('/_database', (req, res) => {
  res.send(`
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Database</title>
    </head>
    <body>
      <h1>_database</h1>
      <pre>${JSON.stringify(_database, null, 2)}</pre>
    </body>
    </html>
  `);
});

app.listen(port, () => {
  console.log(`Dirb lab app listening at http://localhost:${port}`);
});

