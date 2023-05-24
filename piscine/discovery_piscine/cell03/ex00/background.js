/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:23:22 by kichkiro          #+#    #+#             */
/*   Updated: 2023/03/08 23:11:33 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Change background color on click ------------------------------------------->

var button = document.getElementById("myButton");
var isClicked = false;

button.addEventListener("click", function() {
  if (isClicked)
    document.body.style.backgroundColor = "yellow";
  else
    document.body.style.backgroundColor = "green";
  isClicked = !isClicked;
});
