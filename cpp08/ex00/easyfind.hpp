/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:24:14 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/11 17:24:14 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdlib.h>

template <typename T>
typename T::iterator easyfind(T &src_container, int i)
{
    typename T::iterator iter = std::find(src_container.begin(), src_container.end(), i);
    if (iter == src_container.end())
    {
        throw "Value not found in container";
    }
    return (iter);
}

#endif
