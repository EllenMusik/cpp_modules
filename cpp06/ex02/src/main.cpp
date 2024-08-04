/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:07:17 by esteiner          #+#    #+#             */
/*   Updated: 2024/08/02 16:07:17 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Base.hpp"
#include "../A.hpp"
#include "../B.hpp"
#include "../C.hpp"

int	main()
{
    Base *newGeneratedClass;

    newGeneratedClass = generate();
    identify(newGeneratedClass);
    identify(*newGeneratedClass);
    delete newGeneratedClass;
    std::cout << std::endl;

    newGeneratedClass = generate();
    identify(&(*newGeneratedClass));
    identify(*newGeneratedClass);
    delete newGeneratedClass;
    std::cout << std::endl;

    newGeneratedClass = generate();
    identify(newGeneratedClass);
    identify(*newGeneratedClass);
    delete newGeneratedClass;
    std::cout << std::endl;

    return (0);
}