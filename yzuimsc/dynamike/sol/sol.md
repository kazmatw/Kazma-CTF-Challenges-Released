# Writeup 

## Deploy
```bash
node app.js
```

## Web Scanning
```bash
# Use dirb on your local network, below are only explample
dirb http://nothing.kazma.tw
dirb http://10.129.0.57:3000
```

## Break the Password
```bash
hashcat -m 0 -a 0 hashes.txt /usr/share/wordlists/rockyou.txt
```
