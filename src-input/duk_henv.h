/*
 *  Environment object representation.
 */

#if !defined(DUK_HENV_H_INCLUDED)
#define DUK_HENV_H_INCLUDED

#define DUK_ASSERT_HDECENV_VALID(h) do { \
		DUK_ASSERT((h) != NULL); \
		DUK_ASSERT(DUK_HOBJECT_IS_DECENV((duk_hobject *) (h))); \
	} while (0)

#define DUK_ASSERT_HOBJENV_VALID(h) do { \
		DUK_ASSERT((h) != NULL); \
		DUK_ASSERT(DUK_HOBJECT_IS_OBJENV((duk_hobject *) (h))); \
	} while (0)

struct duk_hdecenv {
	/* Shared object part. */
	duk_hobject obj;

	/* These control variables provide enough information to access live
	 * variables for a closure that is still open.  If thread == NULL,
	 * the record is closed and the identifiers are in the property table.
	 */

	duk_hthread *thread;
	duk_hobject *varmap;
	duk_size_t regbase;
};

struct duk_hobjenv {
	/* Shared object part. */
	duk_hobject obj;

	/* Target object and 'this' binding for object binding. */
	/* FIXME: can this_binding be != target? */
	duk_tval this_binding;
	duk_hobject *target;	
};

#endif  /* DUK_HENV_H_INCLUDED */
