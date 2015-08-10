#! /usr/bin/env node


var app = require('express')(),
    server = require('http').createServer(app),
    io = require('socket.io').listen(server);

server.listen(1124, '0.0.0.0');

app.use(function(req, res, next) {
    // Website you wish to allow to connect
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost');
    // Request methods you wish to allow
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
    // Request headers you wish to allow
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');
    // Set to true if you need the website to include cookies in the requests sent
    // to the API (e.g. in case you use sessions)
    res.setHeader('Access-Control-Allow-Credentials', true);
    // Pass to next layer of middleware
    next();
});
app.get('/', function(req, res) {
    res.sendFile(__dirname + '/index.html');
    // res.sendFile('/home/wallace/socketlog' + '/client/index.html');
});

io.sockets.on('connection', function(socket) {
            socket.emit('connected');
            socket.on('my other event', function(data) {
                console.log(data);
            });
});

// var net = require('net');
// var HOST = '0.0.0.0';
// var PORT = 6969;
// net.createServer(function(sock) {
//     // console.log('CONNECTED: ' + sock.remoteAddress + ':' + sock.remotePort);
//     sock.on('data', function(data) {
//         // console.log(sock.remoteAddress + ': ' + data);
//         var msg = '' + data;
//         console.log(msg)
//         // var msg = sock.remoteAddress + ': ' + data;
//         // sock.write('You said "' + data + '"');
//         io.emit('data', msg);
//     });
//     sock.on('close', function(data) {
//         // console.log('CLOSED: ' + sock.remoteAddress + ' ' + sock.remotePort);
//     });
// }).listen(PORT, HOST);

var dgram = require("dgram");
var server = dgram.createSocket("udp4");

server.on("message", function (msg, rinfo) {
    console.log(msg.toString());
});

server.on("listening", function () {
    var address = server.address();
    console.log("server listening " + address.address + ":" + address.port);
});

server.bind(6969);
