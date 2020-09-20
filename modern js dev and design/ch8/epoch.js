function updateDuration(){
	'use strict';
	var now = new Date();
	var message = 'It has been ' + now.getTime();
	message += ' seconds since the epoch. (mouseover to update)';

	U.setText('output', message);
}

window.onload = function()	{
	'use strict';
	U.addEvent(U.$('epoch'), 'mousedown', updateDuration);
	updateDuration();
}
