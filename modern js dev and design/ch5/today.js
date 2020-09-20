function init()	{
  'use strict';
  var today = new Date();
  var message = 'Right now it is ' + today.toLocaleDateString();
  message += ' at ' + today.getHours() + ':' + today.getMinutes();
  
  var output = document.getElementById('output');
  
  if (output.textContent != undefined) {
    output.textContent = message;
  } else {
    output.innerText = message;
  }
}

window.onload = init;