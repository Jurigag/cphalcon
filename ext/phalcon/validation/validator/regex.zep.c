
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Phalcon\Validation\Validator\Regex
 *
 * Allows validate if the value of a field matches a regular expression
 *
 *<code>
 *use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 *$validator->add('created_at', new RegexValidator(array(
 *   'pattern' => '/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/',
 *   'message' => 'The creation date is invalid'
 *)));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Regex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Regex, phalcon, validation_validator_regex, phalcon_validation_validator_ce, phalcon_validation_validator_regex_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Regex, validate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool failed;
	zval *field = NULL;
	zval *validation, *field_param = NULL, *matches, *message = NULL, *value = NULL, *label = NULL, *replacePairs, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (unlikely(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(field, field_param);
	} else {
		ZEPHIR_INIT_VAR(field);
		ZVAL_EMPTY_STRING(field);
	}


	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "pattern", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_preg_match(_0, _1, value, matches, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		zephir_array_fetch_long(&_3, matches, 0, PH_NOISY | PH_READONLY, "phalcon/validation/validator/regex.zep", 58 TSRMLS_CC);
		failed = !ZEPHIR_IS_EQUAL(_3, value);
	} else {
		failed = 1;
	}
	if (failed == 1) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "label", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(label)) {
			ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, field);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "message", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&message, this_ptr, "getoption", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(replacePairs);
		zephir_create_array(replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		if (ZEPHIR_IS_EMPTY(message)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "Regex", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&message, validation, "getdefaultmessage", NULL, 0, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phalcon_validation_message_ce);
		ZEPHIR_CALL_FUNCTION(&_4, "strtr", NULL, 54, message, replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "Regex", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 440, _4, field, _5);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, _2);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

