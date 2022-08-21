import factory

import factory
from factory.django import DjangoModelFactory
from django.conf import settings


class UserFactory(DjangoModelFactory):
    username = factory.Sequence('testuser{}'.format)
    email = factory.Sequence('testuser{}@example.com'.format)
    password = factory.Sequence('TestuserPasssword!{}'.format)

    class Meta:
        model = settings.AUTH_USER_MODEL


class CounterFactory(factory.django.DjangoModelFactory):
    class Meta:
        model = 'core.Counter'

    user = factory.SubFactory(UserFactory)
