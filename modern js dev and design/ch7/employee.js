var employees = [];
var message = '';

function process() {
	'use strict';
	var firstName = document.getElementById('firstName').value;
	var lastName = document.getElementById('lastName').value
	var department = document.getElementById('department').value

	var output = document.getElementById('output');

	var employee = {
		firstName: firstName,
		lastName: lastName,
		department: department,
		getName: function(){
			return this.lastName + ', ' + this.firstName;
		},
		hireDate: new Date()
	};

	employees.push(employee);

	message += 'Name: ' + employee.getName() + '<br>';
	message += 'Department: ' + employee.department + '<br>';
	message += 'Hire Date: ' + employee.hireDate.toDateString();
	message += '<br><br>';
	
	output.innerHTML = message;

	return false;
}

function init() {
	'use strict';
	document.getElementById('theForm').onsubmit = process;
	document.getElementById('theForm').onsubmit = process;
}

window.onload = init;
