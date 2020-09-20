function setText (elementId, message) {
	'use strict';

	if ( (typeof elementId == 'string') && (typeof message == 'string') ) {
		var output = document.getElementById(elementId);
		if (output.textContent != undefined) {
		  output.textContent = message;
		} else {
		  output.innerText = message;
		}
	};
}
function init()	{
  'use strict';
  var today = new Date();
  var message = 'Right now it is ' + today.toLocaleDateString();
  message += ' at ' + today.getHours() + ':' + today.getMinutes();
  
  setText('output', message);
  
}

window.onload = init;
