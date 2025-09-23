/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:53:12 by aperceva          #+#    #+#             */
/*   Updated: 2025/09/23 12:38:40 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);
		int getRawBits() const;
		void setRawBits(int const raw);
};
