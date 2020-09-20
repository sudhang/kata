function validateForm(e){
	'use strict';
	if (typeof e == 'undefined') e = window.event;

	var firstName = U.$('firstName');
	var lastName = U.$('lastName');
	var email = U.$('email');
	var phone = U.$('phone');
	var city = U.$('city');
	var state = U.$('state');
	var zip = U.$('zip');
	var terms = U.$('terms');

	var error = false;

	if(/^[A-Z \.\-']{2,20}$/i.test(firstName.value))	{
		removeErrorMessage("firstName");
	} else {
		addErrorMessage('firstName', 'Please enter your first name');
		error = true;
	}

	// validate the email address
	if (/^[\w.-]+@[\w.-]+\.[A-Za-z]{2,6}$/.test(email.value)){
		removeErrorMessage('email');
	} else {
		addErrorMessage('email', 'Please enter your email address');
		error = true;
	}


	// validate the phone number
	if (/^\d{3}[ \-\.]?\d{3}[ \-\.]?\d{4}$/.test(phone.value)){
		removeErrorMessage('phone');
	} else {
		addErrorMessage('phone', 'Please enter your phone number');
		error = true;
	}

	// validate the state
	if (state.selectedIndex != 0){
		removeErrorMessage('state');
	} else {
		addErrorMessage('state', 'Please enter your state');
		error = true;
	}

	// validate the zip code
	if (/^\d{5}(-\d{4})?$/.test(zip.value)){
		removeErrorMessage('zip');
	} else {
		addErrorMessage('zip', 'Please enter your zip code');
		error = true;
	}

	if (error){
		if (e.preventDefault){
			e.preventDefault();
		} else {
			e.returnValue = false;
		}

		return false;
	}
}

function toggleSubmit(){
	'use strict';

	var submit = U.$('submit');

	if (U.$('terms').checked){
		submit.disabled = false;
	} else {
		submit.disabled = true;
	}
}

window.onload = function()	{
	'use strict';

	U.addEvent(U.$('theForm'), 'submit', validateForm);
	U.$('submit').disabled = true;
	U.addEvent(U.$('terms'), 'change', toggleSubmit);
	U.enableTooltips('phone');
};
