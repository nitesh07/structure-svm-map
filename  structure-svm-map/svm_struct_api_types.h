/***********************************************************************/
/*                                                                     */
/*   svm_struct_api_types.h                                            */
/*                                                                     */
/*   Definition of API for attaching implementing SVM learning of      */
/*   structures (e.g. parsing, multi-label classification, HMM)        */
/*                                                                     */
/*   Author: Thorsten Joachims                                         */
/*   Date: 13.10.03                                                    */
/*                                                                     */
/*   Copyright (c) 2003  Thorsten Joachims - All rights reserved       */
/*                                                                     */
/*   This software is available for non-commercial use only. It must   */
/*   not be modified and distributed without prior permission of the   */
/*   author. The author is not responsible for implications from the   */
/*   use of this software.                                             */
/*                                                                     */
/***********************************************************************/

#ifndef svm_struct_api_types
#define svm_struct_api_types

# include "svm_light/svm_common.h"
# include "svm_light/svm_learn.h"

# define INST_NAME          "SVM-map"
# define INST_VERSION       "V1.00"
# define INST_VERSION_DATE  "05-17-07"

/* default precision for solving the optimization problem */
# define DEFAULT_EPS         0.1
/* default loss rescaling method: 1=slack_rescaling, 2=margin_rescaling */
# define DEFAULT_RESCALING   2
/* default loss function: */
# define DEFAULT_LOSS_FCT    0
/* default optimization algorithm to use: */
# define DEFAULT_ALG_TYPE    1

typedef struct pattern {
    /* this defines the x-part of a training example, e.g. the structure
       for storing a natural language sentence in NLP parsing */

    /* An embedded Python object encodes the item.  The Python code is
       what interacts with a pattern on a fine granularity, so the C
       code doesn't require much else.  This is kept as a void pointer
       so we can avoid having everything that includes this type file
       also have to include Python.h.  However, this really points to a
       PyObject structure type. */
    void *py_pattern;
} PATTERN;

typedef struct label {
    /* this defines the y-part (the label) of a training example,
       e.g. the parse tree of the corresponding sentence. */
    int add_your_variables_here;
    /* An embedded Python object encodes the label.  Again, this is more
       properly a PyObject * pointer. */
    void *py_label;
} LABEL;

typedef struct structmodel {
    double *w;          /* pointer to the learned weights */
    MODEL  *svm_model;  /* the learned SVM model */
    long   sizePsi;     /* maximum number of weights in w */
    /* other information that is needed for the stuctural model can be
       added here, e.g. the grammar rules for NLP parsing */
    void *py_sm;
    int dirty; /* Does the Python representation need refreshing? (How lame!) */
} STRUCTMODEL;

typedef struct struct_learn_parm {
    double epsilon;              /* precision for which to solve
				  quadratic program */
    double newconstretrain;      /* number of new constraints to
				  accumulate before recomputing the QP
				  solution (used in w=1 algorithm) */
    int    ccache_size;          /* maximum number of constraints to
				  cache for each example (used in w=4
				  algorithm) */
    double C;                    /* trade-off between margin and loss */
    char   custom_argv[20][300]; /* string set with the -u command line option */
    int    custom_argc;          /* number of -u command line options */
    int    slack_norm;           /* norm to use in objective function
                                  for slack variables; 1 -> L1-norm,
				  2 -> L2-norm */
    int    loss_type;            /* selected loss function from -r
				  command line option. Select between
				  slack rescaling (1) and margin
				  rescaling (2) */
    int    loss_function;        /* select between different loss
				  functions via -l command line
				  option */
    /* further parameters that are passed to init_struct_model() */
    void *py_sparm;
} STRUCT_LEARN_PARM;

typedef struct struct_test_stats {
    /* you can add variables for keeping statistics when evaluating the
       test predictions in svm_struct_classify. This can be used in the
       function eval_prediction and print_struct_testing_stats. */
    void *py_stats;
} STRUCT_TEST_STATS;

#endif
