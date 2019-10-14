<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

/**
 * Class GetChangedFieldsCest
 */
class GetChangedFieldsCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: getChangedFields() - keepSnapshots
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelGetChangedFieldsKeepSnapshots(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - getChangedFields() - keepSnapshots');
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $I->expectThrowable(
            new Exception(
                "The 'keepSnapshots' option must be enabled to track changes"
            ),
            function () {
                $robot = Robots::findFirst();
                $fields = $robot->getChangedFields();
            }
        );
    }
}
