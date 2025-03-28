/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:29:27 by kichkiro          #+#    #+#             */
/*   Updated: 2024/05/03 14:59:31 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
    Data       *ptr;
    uintptr_t   integer;

    ptr = new Data;
    ptr->value = 42; // Assegna un valore a ptr->value per verificare che sia accessibile dopo la deserializzazione
    integer = Serializer::serialize(ptr);

    std::cout << "ptr addr:    " << ptr << std::endl;
    std::cout << "serialize:   " << integer << std::endl;
    
    // Effettua la deserializzazione
    Data *deserializedPtr = Serializer::deserialize(integer);

    // Verifica che deserializedPtr sia diverso da nullptr prima di accedere ai suoi membri
    if (deserializedPtr) {
        std::cout << "deserialize: " << deserializedPtr << std::endl;
        std::cout << "value:       " << deserializedPtr->value << std::endl;
    } else {
        std::cerr << "Errore durante la deserializzazione: il puntatore è nullo" << std::endl;
    }

    // Dealloca la memoria allocata
    delete ptr;
    
    // Dealloca la memoria deserializzata solo se non è nullo
    // if (deserializedPtr) {
    //     delete deserializedPtr;
    // }

    return 0;
}
