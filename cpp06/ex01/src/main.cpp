/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:04:36 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/07 17:38:21 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Serializer.hpp"
#include "../Data.hpp"
#include <stdint.h>
#include "../colors.hpp"



int main() {
    Data originalData = {1, "Test", 3.14f};

    // Serializing the pointer
    uintptr_t raw = Serializer::serialize(&originalData);

    // Deserializing the raw value
    Data* deserializedData = Serializer::deserialize(raw);

    // Verifying that the deserialized pointer is equal to the original pointer
    if (deserializedData == &originalData) {
        std::cout << YELLOW2 << "Serialization and deserialization successful! :D" << RST   << std::endl;
        std::cout << "Data: " << deserializedData->id << ", " << deserializedData->name << ", " << deserializedData->value << std::endl;
    } else {
        std::cerr << "Serialization and deserialization failed! :'(" << std::endl;
    }

    return 0;
}