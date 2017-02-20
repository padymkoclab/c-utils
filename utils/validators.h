/**
 * Validators
 * All return boolean: true or false
 */

#ifndef __VALIDATORS_H__
#define __VALIDATORS_H__

#include <stdio.h>
#include <stdbool.h>


bool
is_valid_url(char value[])
{
    return false;
};


bool
is_valid_filename(char value[])
{
    return false;
};


bool
is_valid_path(char value[])
{
    return false;
};


bool
is_valid_email(char value[])
{
    return false;
};


bool
is_valid_domain(char value[])
{
    return false;
};


bool
is_valid_uuid(char value[])
{
    return false;
};


bool
is_valid_ipv4(char value[])
{
    return false;
};


bool
is_valid_ipv6(char value[])
{
    return false;
};


bool
is_valid_mac_address(char value[])
{
    return false;
};


bool
is_valid_slug(char value[])
{
    return false;
};


/**
 * Tests
 */


void
test_()
{
    is_valid_ipv4("69.89.31.226");
    is_valid_ipv4("98.139.180.149");
    is_valid_ipv4("192.168.1.98");
    is_valid_ipv4("127.0.0.0");
    is_valid_ipv4("0.0.0.0");
    is_valid_ipv4("");
    is_valid_ipv6("2002:4559:1FE2::4559:1FE2");
    is_valid_ipv6("fe80::9e2a:70ff:fe53:c949/64");
    is_valid_ipv6("");
}


#endif // __VALIDATORS_H__
