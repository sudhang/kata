function $(id) {
	'use strict';
	if (typeof id != 'undefined') {
		return document.getElementById(id);
	};
}
function setText(elementId, message) {
	'use strict';
	if ( (typeof elementId == 'string') && (typeof message == 'string') ) {
		var output = $(elementId);
		if (output.textContent !== undefined) {
			output.textContent = message;
		} else {
			output.innerText = message;
		}
	}
}
function getRandomNumber(max) {
	'use strict';
	var n = Math.random();
	if (typeof max == 'number') {
		n *= max;
		n = Math.floor(n);
	}
	return n;
}
function showNumbers() {
  'use strict';
  var numbers = '';
  
  for (var i = 0; i < 6; i++)	{
    numbers += getRandomNumber(100) + ' ';
  }
  
  setText('output', numbers);
}

window.onload = showNumbers;
