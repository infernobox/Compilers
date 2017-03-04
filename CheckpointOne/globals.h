/************************************************
* File: globals.h
* Global types and variables for CMinus
* Authors: Jasmine Kandloosi and Vanessa White
    Originally provided by Fei Song
* February 2017
*************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXCHILDREN 3 /* max amount of children the root can have */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


extern int lineno; /* source line number for listing */

/* The type of statements for the CMinus language */
enum NodeKind { StmtKind, ExpKind, DeclKind, SpecKind };
enum StmtKind { IfK, ReturnK, WhileK, CmpdK, AssignK, CallK };
enum ExpKind  { OpK, ConstK, IdK};
enum DeclKind { VarK, FunK, ParamK };

enum ExpType {Void,Integer, Array};  /* Type specifiers */

struct TreeNode {

	struct TreeNode * child[MAXCHILDREN];
	struct TreeNode * sibling;

	int pos;
	int op;
	int val;
	char * name;
	enum NodeKind nodeKind;
	enum ExpType etype;
	union {
		enum StmtKind stmt;
		enum ExpKind exp;
		enum DeclKind dec;
	//	enum TypeSpec ts;
	}kind;

	/*union {
		int op;
		int val;
		char * name;
	}attr;*/

	// enum TypeSpec type; 

};


#endif