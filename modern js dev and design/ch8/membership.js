function calculate(e) {
  'use strict';
  e = e || window.event;
  var cost;
  var type = U.$('type');
  var years = U.$('years');
  
  if (years && years.value)	{
    years = parseInt(years.value, 10);
  }
  
  if (type && type.value && years && (years > 0)) {
    switch (type.value)	{
      case 'basic':
	cost = 10.00;
	break;
      case 'premium':
	cost = 15.00;
	break;
      case 'gold':
	cost = 20.00;
	break;
      case 'platinum':
	cost = 25.00;
	break;
    }
    
    cost *= years;
    
    // factor in the discount
    if (years > 1) {
      cost *= 0.80;
    }
    
    U.$('cost').value = '$' + cost.toFixed(2);
  } else if(e.type == 'submit') { // Show an error
    U.$('cost').value = 'Please enter valid values.';
  }
  
  if (e.preventDefault)	{
		e.preventDefault();
  }
  else	{
		e.returnVallue = false;
  }
}

function init() {
  'use strict';
      U.$('theForm').onsubmit = calculate;
}

window.onload = function()	{
	'use strict';
	U.addEvent(U.$('theForm'), 'submit', calculate);
	U.addEvent(U.$('type'), 'submit', calculate);
	U.addEvent(U.$('years'), 'submit', calculate);
}
