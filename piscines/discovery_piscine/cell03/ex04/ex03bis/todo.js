/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todo.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:45:36 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:28 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function add_task() {
	var task = prompt("Add new task: ");
	if (task == "") {
	  alert("Empty field!");
	  return;
	}
	else if (!task)
		return ;
	const parent = $("#ft_list");
	const new_child = $('<div></div>');
	new_child.attr("onclick", "remove_task(this)");
	new_child.attr("id", "id_" + Date.now());
	new_child.html(task);
	parent.prepend(new_child);
	document.cookie = "todo_list=" + encodeURIComponent(parent.html());
  }
  
  function remove_task(element) {
	if (confirm("Remove this task?")) {
	  const todo = $("#" + element.id);
	  const parent = todo.parent();
	  todo.remove();
	  document.cookie = "todo_list=" + encodeURIComponent(parent.html());
	}
  }
  
  $(document).ready(function() {
	const todo = get_cookie("todo_list");
	if (todo) {
	  $("#ft_list").html(decodeURIComponent(todo));
	}
  });
  
  function get_cookie(name) {
	const cookie = document.cookie.match('(^|;)\\s*' + name + '\\s*=\\s*([^;]+)');
	return (cookie ? cookie.pop() : '');
  }
  