function showNumbers() {
  'use strict';
  var numbers = '';
  
  for (var i = 0; i < 6; i++)	{
    numbers += parseInt((Math.random() * 100), 10) + ' ';
  }
  
  var output = document.getElementById('output');
  if (output.textContent != undefined) {
    output.textContent = numbers;
  } else {
    output.innerText = numbers;
  }
}

window.onload = showNumbers;