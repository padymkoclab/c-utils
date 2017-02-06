/**
 * Utils for humanize data
 */


/*
    int arr[10] = {
        1,
    }
    int a = 78421;
    printf("%d %s\n", a, intcomma(a));
 */

#ifndef __HUMANIZE_H__
#define __HUMANIZE_H__

#include <stdio.h>
#include <stdlib.h>



/*
>>> humanize.intcomma(12345)
'12,345'
>>> humanize.intword(123455913)
'123.5 million'
>>> humanize.intword(12345591313)
'12.3 billion'

4500 becomes 4,500.
4500.2 becomes 4,500.2.
45000 becomes 45,000.
450000 becomes 450,000.
4500000 becomes 4,500,000.
Format localization will be respected if enabled, e.g. with the 'de' language:

45000 becomes '45.000'.
450000 becomes '450.000'
 */
static char *
intcomma(const int number) {
    return "";
}


/*
slugify("Cet été, j’en ai rien à coder");
// => "cet-ete-j-en-ai-rien-a-coder"

slugify("\nキャンパス//.Я_♥@борщ\n^abc");
// => "kiyanpasu-ia-borshch-abc"


txt = "This is a test ---"
    r = slugify(txt)
    self.assertEqual(r, "this-is-a-test")

    txt = "___This is a test ---"
    r = slugify(txt)
    self.assertEqual(r, "this-is-a-test")

    txt = "___This is a test___"
    r = slugify(txt)
    self.assertEqual(r, "this-is-a-test")

    txt = "This -- is a ## test ---"
    r = slugify(txt)
    self.assertEqual(r, "this-is-a-test")

    txt = '影師嗎'
    r = slugify(txt)
    self.assertEqual(r, "ying-shi-ma")

    txt = 'C\'est déjà l\'été.'
    r = slugify(txt)
    self.assertEqual(r, "c-est-deja-l-ete")

    txt = 'Nín hǎo. Wǒ shì zhōng guó rén'
    r = slugify(txt)
    self.assertEqual(r, "nin-hao-wo-shi-zhong-guo-ren")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt)
    self.assertEqual(r, "jaja-lol-mememeoo-a")

    txt = 'Компьютер'
    r = slugify(txt)
    self.assertEqual(r, "kompiuter")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=9)
    self.assertEqual(r, "jaja-lol")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=15)
    self.assertEqual(r, "jaja-lol-mememe")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=50)
    self.assertEqual(r, "jaja-lol-mememeoo-a")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=15, word_boundary=True)
    self.assertEqual(r, "jaja-lol-a")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=17, word_boundary=True)
    self.assertEqual(r, "jaja-lol-mememeoo")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=18, word_boundary=True)
    self.assertEqual(r, "jaja-lol-mememeoo")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=19, word_boundary=True)
    self.assertEqual(r, "jaja-lol-mememeoo-a")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=20, word_boundary=True, separator=".")
    self.assertEqual(r, "jaja.lol.mememeoo.a")

    txt = 'jaja---lol-méméméoo--a'
    r = slugify(txt, max_length=20, word_boundary=True, separator="ZZZZZZ")
    self.assertEqual(r, "jajaZZZZZZlolZZZZZZmememeooZZZZZZa")

    txt = 'one two three four five'
    r = slugify(txt, max_length=13, word_boundary=True, save_order=True)
    self.assertEqual(r, "one-two-three")

    txt = 'one two three four five'
    r = slugify(txt, max_length=13, word_boundary=True, save_order=False)
    self.assertEqual(r, "one-two-three")

    txt = 'one two three four five'
    r = slugify(txt, max_length=12, word_boundary=True, save_order=False)
    self.assertEqual(r, "one-two-four")

    txt = 'one two three four five'
    r = slugify(txt, max_length=12, word_boundary=True, save_order=True)
    self.assertEqual(r, "one-two")

    txt = 'this has a stopword'
    r = slugify(txt, stopwords=['stopword'])
    self.assertEqual(r, 'this-has-a')

    txt = 'the quick brown fox jumps over the lazy dog'
    r = slugify(txt, stopwords=['the'])
    self.assertEqual(r, 'quick-brown-fox-jumps-over-lazy-dog')

    txt = 'Foo A FOO B foo C'
    r = slugify(txt, stopwords=['foo'])
    self.assertEqual(r, 'a-b-c')

    txt = 'Foo A FOO B foo C'
    r = slugify(txt, stopwords=['FOO'])
    self.assertEqual(r, 'a-b-c')

    txt = 'the quick brown fox jumps over the lazy dog in a hurry'
    r = slugify(txt, stopwords=['the', 'in', 'a', 'hurry'])
    self.assertEqual(r, 'quick-brown-fox-jumps-over-lazy-dog')

    txt = 'foo &amp; bar'
    r = slugify(txt)
    self.assertEqual(r, 'foo-bar')

 */
static char *
slugify(const char string) {
    return "";
}


/*
// https://github.com/hugopeixoto/humanize/blob/master/humanize.c
>>> humanize.naturalsize(1000000)
'1.0 MB'
>>> humanize.naturalsize(1000000, binary=True)
'976.6 KiB'
>>> humanize.naturalsize(1000000, gnu=True)
'976.6K'
 */
static char *
binary_prefix(const int number) {
    return "";
}


/*
>>> import datetime
>>> humanize.naturalday(datetime.datetime.now())
'today'
>>> humanize.naturaldelta(datetime.timedelta(seconds=1001))
'16 minutes'
>>> humanize.naturalday(datetime.datetime.now() - datetime.timedelta(days=1))
'yesterday'
>>> humanize.naturalday(datetime.date(2007, 6, 5))
'Jun 05'
>>> humanize.naturaldate(datetime.date(2007, 6, 5))
'Jun 05 2007'
>>> humanize.naturaltime(datetime.datetime.now() - datetime.timedelta(seconds=1))
'a second ago'
>>> humanize.naturaltime(datetime.datetime.now() - datetime.timedelta(seconds=3600))
'an hour ago'

Examples (when ‘today’ is 17 Feb 2007):

16 Feb 2007 becomes yesterday.
17 Feb 2007 becomes today.
18 Feb 2007 becomes tomorrow.
 */
static char *
naturalday(const int number) {
    return "";
}


static char *
natural_time_delta(const int number) {
    return "";
}


/*
Examples (when ‘now’ is 17 Feb 2007 16:30:00):

17 Feb 2007 16:30:00 becomes now.
17 Feb 2007 16:29:31 becomes 29 seconds ago.
17 Feb 2007 16:29:00 becomes a minute ago.
17 Feb 2007 16:25:35 becomes 4 minutes ago.
17 Feb 2007 15:30:29 becomes 59 minutes ago.
17 Feb 2007 15:30:01 becomes 59 minutes ago.
17 Feb 2007 15:30:00 becomes an hour ago.
17 Feb 2007 13:31:29 becomes 2 hours ago.
16 Feb 2007 13:31:29 becomes 1 day, 2 hours ago.
16 Feb 2007 13:30:01 becomes 1 day, 2 hours ago.
16 Feb 2007 13:30:00 becomes 1 day, 3 hours ago.
17 Feb 2007 16:30:30 becomes 30 seconds from now.
17 Feb 2007 16:30:29 becomes 29 seconds from now.
17 Feb 2007 16:31:00 becomes a minute from now.
17 Feb 2007 16:34:35 becomes 4 minutes from now.
17 Feb 2007 17:30:29 becomes an hour from now.
17 Feb 2007 18:31:29 becomes 2 hours from now.
18 Feb 2007 16:31:29 becomes 1 day from now.
26 Feb 2007 18:31:29 becomes 1 week, 2 days from now.
 */
static char *
naturaltime(const int number) {
    return "";
}


/*
>>> humanize.fractional(1/3)
'1/3'
>>> humanize.fractional(1.5)
'1 1/2'
>>> humanize.fractional(0.3)
'3/10'
>>> humanize.fractional(0.333)
'1/3'
>>> humanize.fractional(1)
'1'
 */
static char *
fractional(const int number) {
    return "";
}


/*
For numbers 1-9, returns the number spelled out. Otherwise, returns the number. This follows Associated Press style.

Examples:

1 becomes one.
2 becomes two.
10 becomes 10.
 */
static char *
apnumber(const int number) {
    return "";
}


/*
Converts a large integer (or a string representation of an integer) to a friendly text representation. Works best for numbers over 1 million.

Examples:

1000000 becomes 1.0 million.
1200000 becomes 1.2 million.
1200000000 becomes 1.2 billion.
Values up to 10^100 (Googol) are supported.

Format localization will be respected if enabled, e.g. with the 'de' language:

1000000 becomes '1,0 Million'.
1200000 becomes '1,2 Million'.
1200000000 becomes '1,2 Milliarden'.
 */
static char *
intword(const int number) {
    return "";
}


/*
Converts an integer to its ordinal as a string.

Examples:

1 becomes 1st.
2 becomes 2nd.
3 becomes 3rd.
 */
static char *
ordinal(const int number) {
    return "";
}


#endif // __HUMANIZE_H__
