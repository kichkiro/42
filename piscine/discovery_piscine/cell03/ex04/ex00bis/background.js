/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:06 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/09 15:58:07 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Change background color on click ------------------------------------------->

$(document).ready(function() {
	var button = $("#myButton");
	var isClicked = false;
  
	button.on("click", function() {
	  if (isClicked) {
		$("body").css("background-color", "yellow");
	  } else {
		$("body").css("background-color", "green");
	  }
	  isClicked = !isClicked;
	});
  });
  