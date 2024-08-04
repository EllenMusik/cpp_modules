/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:23:46 by esteiner          #+#    #+#             */
/*   Updated: 2024/07/29 15:23:46 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Serializer.hpp"
#include "../Data.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &src) {
    *this = src;
}

Serializer::~Serializer() {
}

Serializer &Serializer::operator=(const Serializer &src) {
    if (this == &src)
        return *this;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}