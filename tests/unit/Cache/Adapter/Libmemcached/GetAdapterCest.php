<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Adapter\Libmemcached;

use Memcached;
use Phalcon\Cache\Adapter\Libmemcached;
use Phalcon\Test\Fixtures\Traits\LibmemcachedTrait;
use UnitTester;

/**
 * Class GetAdapterCest
 */
class GetAdapterCest
{
    use LibmemcachedTrait;

    /**
     * Tests Phalcon\Cache\Adapter\Libmemcached :: getAdapter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-14
     */
    public function cacheAdapterLibmemcachedGetAdapter(UnitTester $I)
    {
        $I->wantToTest('Cache\Adapter\Libmemcached - getAdapter()');
        $adapter = new Libmemcached($this->getOptions());

        $class  = Memcached::class;
        $actual = $adapter->getAdapter();
        $I->assertInstanceOf($class, $actual);
    }
}