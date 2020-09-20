window.onload = function()	{
	'use strict';

	var target = document.getElementById('target');

	var opacity = 100;
	var fader = setInterval(function()	{
		opacity -= 10;

		if (opacity >= 0)	{
			if (typeof target.style.opacity == 'string'){
				target.style.opacity = (opacity/100);
			} else {
				target.style.filter = 'alpha(opacity=' + opacity + ')';
			}
		} else {
			clearInterval(fader);
		}
	}, 100);
};
