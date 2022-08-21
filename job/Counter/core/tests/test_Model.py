from .Factories import CounterFactory
from .Factories import UserFactory
from django.db import IntegrityError
from django.db.transaction import TransactionManagementError
import pytest

@pytest.mark.django_db
def test_model():
    counter = CounterFactory()

    assert counter.count == 0

    counter.count += 1
    assert counter.count == 1

    counter.count += 20
    assert counter.count == 21

    counter.count -= 20
    counter.count += 1
    assert counter.count == 2

# тест для демонстрации,что значения меньше нуля не принимаются в данной задаче
@pytest.mark.django_db
def test_constrains():
    counter = CounterFactory()

    with pytest.raises(IntegrityError) as excinfo:
        counter.count -= 20
        counter.save()








