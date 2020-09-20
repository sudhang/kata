var COOKIE = {
	setCookie: function(name, value, expire) {
		'use strict';
		var str = encodeURIComponent(name) + '=' + encodeURIComponent(value);
		str += ';expires=' + expire.toGMTString();
		document.cookie = str;
	},
	getCookie: function(name){
		'use strict';
		var len = name.length;
		var cookies = document.cookie.split(';');

		for (var i = 0; i < cookies.length; i++){
			var value = (cookies[i].slice(0,1) == ' ') ? cookies[i].slice(1) : cookies[i];
			value = decodeURIComponent(value);
			if (value.slice(0, len) == name){
				return cookies[i].split('=')[1];
			}
		}
		return false;
	},
	deleteCookie: function(name)	{
		'use strict';
		document.cookie = encodeURIComponent(name) + '=;expires=Thu, 01-Jan-1970 00:00:01 GMT';
	}
};
