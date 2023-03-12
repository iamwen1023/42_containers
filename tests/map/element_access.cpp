/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:56:18 by avan-bre          #+#    #+#             */
/*   Updated: 2022/09/09 16:56:21 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "parameters.hpp"

TYPED_TEST_SUITE_P(MapElementAccess);

TYPED_TEST(MapElementAccess, SquareBrackets){
	MAP				m1;

	m1[1] = 'a';
	m1[2] = 'b';
	m1[3] = 'c';

	EXPECT_EQ(m1[1], 'a');
	EXPECT_EQ(m1[3], 'c');
};
