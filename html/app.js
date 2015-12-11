var express = require('express'),
	app = express(),
	server = require('http').createServer(app),
	SerialPort = require("serialport").SerialPort;
	io = require('socket.io').listen(server);

server.listen(3000);
app.get('/', function(req, res){
	res.sendfile(__dirname + '/index.html');
});

var serialport = new SerialPort("/dev/ttyACM0");
serialport.on('open', function(){

	console.log('Serial Port Opened');

	var lastValue;
	io.sockets.on('connection', function (socket){
		console.log('Socket connected');
		socket.emit('new message', 'connected');
	serialport.on('data',function(data){
	socket.emit('new message', data)
});

});
});
io.sockets.on('connection', function(socket){
	socket.on('send message', function(data){
		io.sockets.emit('new message', data);
	});
});
