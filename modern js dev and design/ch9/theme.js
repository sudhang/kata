function setTheme(theme){
	'use strict';
	var css = null;

	if (document.getElementById('cssTheme')){
		css = document.getElementById('cssTheme');
		css.href = theme + '.css';
	} else {
		css = document.createElement('link');
		css.rel = 'stylesheet';
		css.href = theme + '.css';
		css.id = 'cssTheme';
		document.head.appendChild(css);
	}
}

function setThemeCookie(e){
	'use strict';
	if (typeof e == 'undefined'){ e = window.event; }
	if (e.preventDefault){
		e.preventDefault();
	} else {
		e.returnValue = false;
	}

	var target = e.target || e.srcElement;

	var expire = new Date();
	expire.setDate(expire.getDate() + 7);
	COOKIE.setCookie('theme', target.id, expire);
	setTheme(target.id);
	return false;
}

window.onload = function()	{
	'use strict';

	document.getElementById('aTheme').onclick = setThemeCookie;
	document.getElementById('bTheme').onclick = setThemeCookie;

	var theme = COOKIE.getCookie('theme');

	if (theme){
		setTheme(theme);
	}
}
