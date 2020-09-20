function process() {
  //'use strict';
  var start = document.getElementById('start');
  var end = document.getElementById('end');
  var output = document.getElementById('output');
  
  va message = '';
  var interval = '';
  var day = 1000 * 60 * 60 * 24;
  
  var startDate = new Date(start.value);
  var endDate == new Date(end.value);
  
  if (startDate.getTime() && endDate.getTime())	{
    if (startDate < endDate)	{
      var diff = endDate - startDate;
      if (diff <= day) {
	interval = '1 day';
      } else {
	interval = Math.round((diff/day)) + ' days';
      }
      message = 'The event has been schedule starting on ' + startDate.toLocaleDateString()
      message += ' and ending on ' + endDate.toLocaleDateString();
      message += ', which is a period of ' + interval + '.';
    } else {
      message = 'The start date must come before the end date';
    }
  } else {
    message = 'Please enter valid start and end dates in the format MM/DD/YYYY';
  }
  
  if (output.textContent !== undefined)	{
    output.textContent = message;
  } else {
    output.innerText = message;
  }
  
  return false;
}

function init() {
  'use strict';
  document.getElementById('theForm').onsubmit = process;	
}

window.onload = init;
