function Task(name, priority){
	'use strict';

	this.toString = function()	{
		return this.name + '(' + this.priority + ')';
	};

	this.name = name;
	this.priority = priority;
	this.completed = false;
}

window.onload = function()	{
	'use strict';

	var task = document.getElementById('task');
	var priority = document.getElementById('priority');
	var output = document.getElementById('output');

	var tasks = [];
	document.getElementById('theForm').onsubmit = function()	{
		var t = new Task(task.value, priority.value);
	    tasks.push(t);

	    output.innerHTML = 'There are now <b>' + tasks.length + '</b> item(s) in the to-do list. Just added: <br>' + t.toString();
	    return false;
	};
};
