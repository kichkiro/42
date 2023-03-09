/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:57:28 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/09 17:01:35 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function add_task() {
	var task = prompt("Add new task: ");
	if (task == "") {
		alert("Empty field!");
		return ;
	}
	else if (!task)
		return ;
	const parent = document.getElementById("ft_list");
	const new_child = document.createElement('div');
	new_child.setAttribute("onclick", "remove_task(this)");
	new_child.setAttribute("id", "id_" + Date.now());
	new_child.innerHTML = task;
	parent.insertBefore(new_child, parent.firstChild);
	document.cookie = "todo_list=" + encodeURIComponent(parent.innerHTML);
}

function remove_task(element) {
	if (confirm("Remove this task?")) {
		const todo = document.getElementById(element.id);
		const parent = todo.parentNode;
		parent.removeChild(todo);
		document.cookie = "todo_list=" + encodeURIComponent(parent.innerHTML);
	}
}

window.onload = function() {
	const todo = get_cookie("todo_list");
	if (todo) {
		document.getElementById("ft_list").innerHTML = decodeURIComponent(todo);
	}
}

function get_cookie(name) {
	const cookie = document.cookie.match('(^|;)\\s*'+name+'\\s*=\\s*([^;]+)');
	return (cookie ? cookie.pop() : '');
}
