/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_INT = 258,
     TK_FLOAT = 259,
     TK_MAIN = 260,
     TK_NUM = 261,
     TK_ID = 262,
     TK_FLOATNUM = 263,
     TK_PRINT = 264,
     TK_READ = 265,
     TK_STRING = 266,
     TK_CHAR = 267,
     TK_BOOLEAN = 268,
     TK_TRUE = 269,
     TK_FALSE = 270,
     TK_CHARLIT = 271,
     TK_LT = 272,
     TK_LE = 273,
     TK_GT = 274,
     TK_GE = 275,
     TK_EQ = 276,
     TK_NE = 277,
     TK_AND = 278,
     TK_OR = 279,
     TK_NOT = 280,
     TK_IF = 281,
     TK_ELSE = 282,
     TK_WHILE = 283,
     TK_DO = 284,
     TK_FOR = 285,
     TK_SWITCH = 286,
     TK_CASE = 287,
     TK_DEFAULT = 288,
     TK_BREAK = 289,
     TK_CONTINUE = 290,
     TK_STRLIT = 291,
     TK_ADDEQ = 292,
     TK_SUBEQ = 293,
     TK_MULTEQ = 294,
     TK_DIVEQ = 295,
     TK_INC = 296,
     TK_DEC = 297
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_FLOAT 259
#define TK_MAIN 260
#define TK_NUM 261
#define TK_ID 262
#define TK_FLOATNUM 263
#define TK_PRINT 264
#define TK_READ 265
#define TK_STRING 266
#define TK_CHAR 267
#define TK_BOOLEAN 268
#define TK_TRUE 269
#define TK_FALSE 270
#define TK_CHARLIT 271
#define TK_LT 272
#define TK_LE 273
#define TK_GT 274
#define TK_GE 275
#define TK_EQ 276
#define TK_NE 277
#define TK_AND 278
#define TK_OR 279
#define TK_NOT 280
#define TK_IF 281
#define TK_ELSE 282
#define TK_WHILE 283
#define TK_DO 284
#define TK_FOR 285
#define TK_SWITCH 286
#define TK_CASE 287
#define TK_DEFAULT 288
#define TK_BREAK 289
#define TK_CONTINUE 290
#define TK_STRLIT 291
#define TK_ADDEQ 292
#define TK_SUBEQ 293
#define TK_MULTEQ 294
#define TK_DIVEQ 295
#define TK_INC 296
#define TK_DEC 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

