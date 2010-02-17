// Use of this software is granted under one of the following two licenses,
// to be chosen freely by the user.

// 1. Boost Software License - Version 1.0 - August 17th, 2003
// ===============================================================================

// Copyright (c) 2010 Emweb bvba (Heverlee, Belgium)

// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:

// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// 2. The MIT License
// ===============================================================================

// Copyright (c) 2010 Emweb bvba (Heverlee, Belgium)

// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal 
// in the Software without restriction, including without limitation the rights 
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
// of the Software, and to permit persons to whom the Software is furnished to do so, 
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all 
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
// IN THE SOFTWARE.
#ifndef RAPIDXML_XHTML_HPP_INCLUDED
#define RAPIDXML_XHTML_HPP_INCLUDED

#include<cstddef>

namespace rapidxml
{
    namespace internal
    {
        template<class Ch> inline std::size_t measure(const Ch *p);
    }

    // returns true if the src could be interpreted as an xhtml entity reference and
    // decoded as utf8 into dest

    template<class Ch>
    bool translate_xhtml_entity(Ch *& src, Ch *& dest)
    {
      // Caveat: assumes output encoding is UTF-8

      const int entity_count = 257;

      struct Entity {
	const char *name;
	const char *utf8;
      } entities[] = {
	{ "AElig", "\xc3\x86" },
	{ "Aacute", "\xc3\x81" },
	{ "Acirc", "\xc3\x82" },
	{ "Agrave", "\xc3\x80" },
	{ "Alpha", "\xce\x91" },
	{ "Aring", "\xc3\x85" },
	{ "Atilde", "\xc3\x83" },
	{ "Auml", "\xc3\x84" },
	{ "Beta", "\xce\x92" },
	{ "Ccedil", "\xc3\x87" },
	{ "Chi", "\xce\xa7" },
	{ "Dagger", "\xe2\x80\xa1" },
	{ "Delta", "\xce\x94" },
	{ "Dstrok", "\xc3\x90" },
	{ "ETH", "\xc3\x90" },
	{ "Eacute", "\xc3\x89" },
	{ "Ecirc", "\xc3\x8a" },
	{ "Egrave", "\xc3\x88" },
	{ "Epsilon", "\xce\x95" },
	{ "Eta", "\xce\x97" },
	{ "Euml", "\xc3\x8b" },
	{ "Gamma", "\xce\x93" },
	{ "Iacute", "\xc3\x8d" },
	{ "Icirc", "\xc3\x8e" },
	{ "Igrave", "\xc3\x8c" },
	{ "Iota", "\xce\x99" },
	{ "Iuml", "\xc3\x8f" },
	{ "Kappa", "\xce\x9a" },
	{ "Lambda", "\xce\x9b" },
	{ "Mu", "\xce\x9c" },
	{ "Ntilde", "\xc3\x91" },
	{ "Nu", "\xce\x9d" },
	{ "OElig", "\xc5\x92" },
	{ "Oacute", "\xc3\x93" },
	{ "Ocirc", "\xc3\x94" },
	{ "Ograve", "\xc3\x92" },
	{ "Omega", "\xce\xa9" },
	{ "Omicron", "\xce\x9f" },
	{ "Oslash", "\xc3\x98" },
	{ "Otilde", "\xc3\x95" },
	{ "Ouml", "\xc3\x96" },
	{ "Phi", "\xce\xa6" },
	{ "Pi", "\xce\xa0" },
	{ "Prime", "\xe2\x80\xb3" },
	{ "Psi", "\xce\xa8" },
	{ "Rho", "\xce\xa1" },
	{ "Scaron", "\xc5\xa0" },
	{ "Sigma", "\xce\xa3" },
	{ "THORN", "\xc3\x9e" },
	{ "Tau", "\xce\xa4" },
	{ "Theta", "\xce\x98" },
	{ "Uacute", "\xc3\x9a" },
	{ "Ucirc", "\xc3\x9b" },
	{ "Ugrave", "\xc3\x99" },
	{ "Upsilon", "\xce\xa5" },
	{ "Uuml", "\xc3\x9c" },
	{ "Xi", "\xce\x9e" },
	{ "Yacute", "\xc3\x9d" },
	{ "Yuml", "\xc5\xb8" },
	{ "Zeta", "\xce\x96" },
	{ "aacute", "\xc3\xa1" },
	{ "acirc", "\xc3\xa2" },
	{ "acute", "\xc2\xb4" },
	{ "aelig", "\xc3\xa6" },
	{ "agrave", "\xc3\xa0" },
	{ "alefsym", "\xe2\x84\xb5" },
	{ "alpha", "\xce\xb1" },
	{ "amp", "\x26" },
	{ "and", "\xe2\x88\xa7" },
	{ "ang", "\xe2\x88\xa0" },
	{ "apos", "\x27" },
	{ "aring", "\xc3\xa5" },
	{ "asymp", "\xe2\x89\x88" },
	{ "atilde", "\xc3\xa3" },
	{ "auml", "\xc3\xa4" },
	{ "bdquo", "\xe2\x80\x9e" },
	{ "beta", "\xce\xb2" },
	{ "brkbar", "\xc2\xa6" },
	{ "brvbar", "\xc2\xa6" },
	{ "bull", "\xe2\x80\xa2" },
	{ "cap", "\xe2\x88\xa9" },
	{ "ccedil", "\xc3\xa7" },
	{ "cedil", "\xc2\xb8" },
	{ "cent", "\xc2\xa2" },
	{ "chi", "\xcf\x87" },
	{ "circ", "\xcb\x86" },
	{ "clubs", "\xe2\x99\xa3" },
	{ "cong", "\xe2\x89\x85" },
	{ "copy", "\xc2\xa9" },
	{ "crarr", "\xe2\x86\xb5" },
	{ "cup", "\xe2\x88\xaa" },
	{ "curren", "\xc2\xa4" },
	{ "dArr", "\xe2\x87\x93" },
	{ "dagger", "\xe2\x80\xa0" },
	{ "darr", "\xe2\x86\x93" },
	{ "deg", "\xc2\xb0" },
	{ "delta", "\xce\xb4" },
	{ "diams", "\xe2\x99\xa6" },
	{ "die", "\xc2\xa8" },
	{ "divide", "\xc3\xb7" },
	{ "eacute", "\xc3\xa9" },
	{ "ecirc", "\xc3\xaa" },
	{ "egrave", "\xc3\xa8" },
	{ "empty", "\xe2\x88\x85" },
	{ "emsp", "\xe2\x80\x83" },
	{ "ensp", "\xe2\x80\x82" },
	{ "epsilon", "\xce\xb5" },
	{ "equiv", "\xe2\x89\xa1" },
	{ "eta", "\xce\xb7" },
	{ "eth", "\xc3\xb0" },
	{ "euml", "\xc3\xab" },
	{ "euro", "\xe2\x82\xac" },
	{ "exist", "\xe2\x88\x83" },
	{ "fnof", "\xc6\x92" },
	{ "forall", "\xe2\x88\x80" },
	{ "frac12", "\xc2\xbd" },
	{ "frac14", "\xc2\xbc" },
	{ "frac34", "\xc2\xbe" },
	{ "frasl", "\xe2\x81\x84" },
	{ "gamma", "\xce\xb3" },
	{ "ge", "\xe2\x89\xa5" },
	{ "gt", "\x3e" },
	{ "hArr", "\xe2\x87\x94" },
	{ "harr", "\xe2\x86\x94" },
	{ "hearts", "\xe2\x99\xa5" },
	{ "hellip", "\xe2\x80\xa6" },
	{ "hibar", "\xc2\xaf" },
	{ "iacute", "\xc3\xad" },
	{ "icirc", "\xc3\xae" },
	{ "iexcl", "\xc2\xa1" },
	{ "igrave", "\xc3\xac" },
	{ "image", "\xe2\x84\x91" },
	{ "infin", "\xe2\x88\x9e" },
	{ "int", "\xe2\x88\xab" },
	{ "iota", "\xce\xb9" },
	{ "iquest", "\xc2\xbf" },
	{ "isin", "\xe2\x88\x88" },
	{ "iuml", "\xc3\xaf" },
	{ "kappa", "\xce\xba" },
	{ "lArr", "\xe2\x87\x90" },
	{ "lambda", "\xce\xbb" },
	{ "lang", "\xe2\x8c\xa9" },
	{ "laquo", "\xc2\xab" },
	{ "larr", "\xe2\x86\x90" },
	{ "lceil", "\xe2\x8c\x88" },
	{ "ldquo", "\xe2\x80\x9c" },
	{ "le", "\xe2\x89\xa4" },
	{ "lfloor", "\xe2\x8c\x8a" },
	{ "lowast", "\xe2\x88\x97" },
	{ "loz", "\xe2\x97\x8a" },
	{ "lrm", "\xe2\x80\x8e" },
	{ "lsaquo", "\xe2\x80\xb9" },
	{ "lsquo", "\xe2\x80\x98" },
	{ "lt", "\x3c" },
	{ "macr", "\xc2\xaf" },
	{ "mdash", "\xe2\x80\x94" },
	{ "micro", "\xc2\xb5" },
	{ "middot", "\xc2\xb7" },
	{ "minus", "\xe2\x88\x92" },
	{ "mu", "\xce\xbc" },
	{ "nabla", "\xe2\x88\x87" },
	{ "nbsp", "\xc2\xa0" },
	{ "ndash", "\xe2\x80\x93" },
	{ "ne", "\xe2\x89\xa0" },
	{ "ni", "\xe2\x88\x8b" },
	{ "not", "\xc2\xac" },
	{ "notin", "\xe2\x88\x89" },
	{ "nsub", "\xe2\x8a\x84" },
	{ "ntilde", "\xc3\xb1" },
	{ "nu", "\xce\xbd" },
	{ "oacute", "\xc3\xb3" },
	{ "ocirc", "\xc3\xb4" },
	{ "oelig", "\xc5\x93" },
	{ "ograve", "\xc3\xb2" },
	{ "oline", "\xe2\x80\xbe" },
	{ "omega", "\xcf\x89" },
	{ "omicron", "\xce\xbf" },
	{ "oplus", "\xe2\x8a\x95" },
	{ "or", "\xe2\x88\xa8" },
	{ "ordf", "\xc2\xaa" },
	{ "ordm", "\xc2\xba" },
	{ "oslash", "\xc3\xb8" },
	{ "otilde", "\xc3\xb5" },
	{ "otimes", "\xe2\x8a\x97" },
	{ "ouml", "\xc3\xb6" },
	{ "para", "\xc2\xb6" },
	{ "part", "\xe2\x88\x82" },
	{ "permil", "\xe2\x80\xb0" },
	{ "perp", "\xe2\x8a\xa5" },
	{ "phi", "\xcf\x86" },
	{ "pi", "\xcf\x80" },
	{ "piv", "\xcf\x96" },
	{ "plusmn", "\xc2\xb1" },
	{ "pound", "\xc2\xa3" },
	{ "prime", "\xe2\x80\xb2" },
	{ "prod", "\xe2\x88\x8f" },
	{ "prop", "\xe2\x88\x9d" },
	{ "psi", "\xcf\x88" },
	{ "quot", "\x22" },
	{ "rArr", "\xe2\x87\x92" },
	{ "radic", "\xe2\x88\x9a" },
	{ "rang", "\xe2\x8c\xaa" },
	{ "raquo", "\xc2\xbb" },
	{ "rarr", "\xe2\x86\x92" },
	{ "rceil", "\xe2\x8c\x89" },
	{ "rdquo", "\xe2\x80\x9d" },
	{ "real", "\xe2\x84\x9c" },
	{ "reg", "\xc2\xae" },
	{ "rfloor", "\xe2\x8c\x8b" },
	{ "rho", "\xcf\x81" },
	{ "rlm", "\xe2\x80\x8f" },
	{ "rsaquo", "\xe2\x80\xba" },
	{ "rsquo", "\xe2\x80\x99" },
	{ "sbquo", "\xe2\x80\x9a" },
	{ "scaron", "\xc5\xa1" },
	{ "sdot", "\xe2\x8b\x85" },
	{ "sect", "\xc2\xa7" },
	{ "shy", "\xc2\xad" },
	{ "sigma", "\xcf\x83" },
	{ "sigmaf", "\xcf\x82" },
	{ "sim", "\xe2\x88\xbc" },
	{ "spades", "\xe2\x99\xa0" },
	{ "sub", "\xe2\x8a\x82" },
	{ "sube", "\xe2\x8a\x86" },
	{ "sum", "\xe2\x88\x91" },
	{ "sup", "\xe2\x8a\x83" },
	{ "sup1", "\xc2\xb9" },
	{ "sup2", "\xc2\xb2" },
	{ "sup3", "\xc2\xb3" },
	{ "supe", "\xe2\x8a\x87" },
	{ "szlig", "\xc3\x9f" },
	{ "tau", "\xcf\x84" },
	{ "there4", "\xe2\x88\xb4" },
	{ "theta", "\xce\xb8" },
	{ "thetasym", "\xcf\x91" },
	{ "thinsp", "\xe2\x80\x89" },
	{ "thorn", "\xc3\xbe" },
	{ "tilde", "\xcb\x9c" },
	{ "times", "\xc3\x97" },
	{ "trade", "\xe2\x84\xa2" },
	{ "uArr", "\xe2\x87\x91" },
	{ "uacute", "\xc3\xba" },
	{ "uarr", "\xe2\x86\x91" },
	{ "ucirc", "\xc3\xbb" },
	{ "ugrave", "\xc3\xb9" },
	{ "uml", "\xc2\xa8" },
	{ "upsih", "\xcf\x92" },
	{ "upsilon", "\xcf\x85" },
	{ "uuml", "\xc3\xbc" },
	{ "weierp", "\xe2\x84\x98" },
	{ "xi", "\xce\xbe" },
	{ "yacute", "\xc3\xbd" },
	{ "yen", "\xc2\xa5" },
	{ "yuml", "\xc3\xbf" },
	{ "zeta", "\xce\xb6" },
	{ "zwj", "\xe2\x80\x8d" },
	{ "zwnj", "\xe2\x80\x8c" }
      };

      // first find ; longest char entity reference is 8 chars (thetasym)
      char entity[9];
      bool entity_ok = false;
      for (unsigned i = 0; i < 9; ++i)
	if (src[1 + i] == ';') {
	  entity[i] = 0;
	  entity_ok = true;
	  break;
	} else
	  entity[i] = src[1 + i];

      if (!entity_ok)
	return false;

      // do binary search for entity in our entity table
      int imin = 0; // inclusive
      int imax = entity_count; // exclusive
      int i;

      for (;;) {
	if (imax - imin <= 1)
	  if (strcmp(entity, entities[imin].name) == 0) {
	    i = imin;
	    break;
	  } else
	    return false; // not found
	else {
	  i = (imin + imax) / 2;
	  int cmp = strcmp(entity, entities[i].name);
	  if (cmp == 0)
	    break;
	  else {
	    if (cmp < 0)
	      imax = i;
	    else
	      imin = i + 1;
	  }
	}
      }

      src += internal::measure(entity) + 2; // + &;
      for (const Ch *c = entities[i].utf8; *c; ++c)
	*dest++ = *c;

      return true;
    }
}

#endif
